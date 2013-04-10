/* 
 * Copyright (c) 2010-2013 <Joseph Babb, Michael Cassollary, Joohyung Lee>
 *
 * For information on how to contact the authors, please visit
 *	http://reasoning.eas.asu.edu/cplus2asp
 *
 * This file is part of the cplus2asp system.
 *
 * cplus2asp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cplus2asp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include <list>

#include "types.h"

/**
 * @file Context.h
 * @brief A data structure used to track the context a formula is found within.
 * @details Tracks the context a formula is found within during translation.
 */

class Context
{
public:
	/// An enum providing the different positions an expression may be located in.
	enum Position { POS_HEAD, POS_BODY, POS_QUERY, POS_TERM, POS_ARITHEXPR, POS_INTERNAL};


	static std::string const TRUE_STR;		///< Concrete default string to instantiate 'true' default values.
	static std::string const FALSE_STR;		///< Concrete default string to instantiate 'false' default values.
	static std::string const EMPTY_STR;		///< Concrete default string to instantiate empty timestamps.
	static std::string const ANON_STR;		///< Concrete default string to instantiate anonymous values / timestamps.
	static std::string const BASE_STR;		///< Concrete default string to instantiate base timestamps.
private:
	Position mPos;				///< The location which the expression occurs within the program.
	IPart mPart;				///< The incremental module we are currently working in.
	bool mNeg; 					///< Whether this expression occurs in the scope of one or more negations.
	bool mPositive;				///< Whether this expression occurs in the scope of an _even_ number of negations.
	std::string const* mVal;	///< The value that the expression should take (where applicable).
	std::string const* mTime;	///< The timestamp to be applied to the expression (where applicable).

	ClauseList* mFreeVars;		///< A pointer to a list to add free variables to (or null if they should be ignored).
	ClauseList* mExtraClauses;	///< A pointer to a list to add extra clauses to (or null if they should be ignored).
	StmtList* mPreStmts;		///< A pointer to a list to add prerequisite statements to (or null if they should be ignored).

public:

	/**
	 * Default Constructor
	 */
	inline Context()
		: mPos(POS_BODY), mPart(IPART_BASE), mNeg(false), mPositive(false), mVal(&TRUE_STR), mTime(&EMPTY_STR),
		  mFreeVars(NULL), mExtraClauses(NULL), mPreStmts(NULL)
		{ /* Intentionally Left Blank */ }

	/**
	 * Basic constructor used for the context for an expression.
	 * @param pos - The position that the formula is located in.
	 * @param ipart - The incremental module the statement is associated with.
	 * @param timestamp - The timestamp that this context is set within.
	 * @param extraClauses - A pointer to a list that extra clauses should be added to (or NULL to ignore them).
	 * @param freeVars - A pointer to a list that free variables should be added to (or NULL to ignore them).
	 * @param negated - Whether this formula occurs in the scope of one or more negations.
	 * @param positive - Whether this formula occurs in the scope of an _even_ number of negations.
	 * @param preStmts - A pointer to a list that prerequisite statements should be added to.
	 */
	inline Context(
			Position pos,
			IPart ipart,
			std::string const& timestamp,
			ClauseList* extraClauses = NULL,
			ClauseList* freeVars = NULL,
			bool negated = false,
			bool positive = true,
			StmtList* preStmts = NULL)
		: mPos(pos), mPart(ipart), mNeg(negated), mPositive(positive), mVal(&TRUE_STR), mTime(&timestamp),
		mFreeVars(freeVars), mExtraClauses(extraClauses), mPreStmts(preStmts)
		{ /* Intentionally Left Blank */}

	/**
	 * Basic constructor used for the context for an expression.
	 * @param pos - The position that the formula is located in.
	 * @param ipart - The incremental module the statement is associated with.
	 * @param timestamp - The timestamp that this context is set within.
	 * @param val - The value that an atomic formula within this context should take.
	 * @param extraClauses - A pointer to a list that extra clauses should be added to (or NULL to ignore them).
	 * @param freeVars - A pointer to a list that free variables should be added to (or NULL to ignore them).
	 * @param negated - Whether this formula occurs in the scope of one or more negations.
	 * @param positive - Whether this formula occurs in the scope of an _even_ number of negations.
	 * @param preStmts - A pointer to a list that prerequisite statements should be added to.
	 */
	inline Context(
			Position pos,
			IPart ipart,
			std::string const& timestamp,
			std::string const& val,
			ClauseList* extraClauses = NULL,
			ClauseList* freeVars = NULL,
			bool negated = false,
			bool positive = true,
			StmtList* preStmts = NULL)
		: mPos(pos), mPart(ipart), mNeg(negated), mPositive(positive), mVal(&val), mTime(&timestamp),
		mFreeVars(freeVars), mExtraClauses(extraClauses), mPreStmts(preStmts)
		{ /* Intentionally Left Blank */}

	/// Basic destructor. Does nothing.
	inline virtual ~Context() { /* Intentionally Left Blank */ }


	/// Copy Constructor
	inline Context(Context const& other) { copy(other); }

	/// Determines whether the formula occurs in the head of a rule.
	inline Position getPos() const { return mPos; }

	/// Determines whether the formula occurs within the scope of negation.
	inline bool getNegated() const { return mNeg; }

	/// Determines whether the formula occurs within an even number of negations.
	inline bool getPositive() const { return mPositive; }

	/// Determines the timestamp which should be applied to the formula
	inline std::string const& getTimestamp() const { return *mTime; }

	/// Determines the value which the formula should be set equal to.
	inline std::string const& getValue() const { return *mVal; }

	/**
	 * Adds a free variable to the list which is binding the context.
	 * @param var The variable to add
	 * @param domain The domain of the variable. If included a #domain statement for the variable will automatically be generated.
	 * @return True if the variable was added, false if nobody has bound the variables in the context.
	 */
	bool addFreeVariable(std::string const& var, Sort const* domain = NULL);

	/**
	 * Adds an extra clause to the list which is binding the context.
	 * @param clause The extra clause to add.
	 * @return True if the clause was added, false if nobody has bound the extra clauses in the context.
	 */
	inline bool addExtraClause(std::string const& clause)	{ if (mExtraClauses) mExtraClauses->push_back(clause); return (bool)mExtraClauses; }

	/**
	 * Adds a prerequisite statement to the list which is binding the context.
	 * @param stmt The statement to add.
	 * @return True if the statement was added, false if nobody has bound the prerequisite statements in the context.
	 */
	inline bool addPreStmt(Statement const& stmt)			{ if (mPreStmts) mPreStmts->push_back(stmt); return (bool)mPreStmts; }



	/**
	 * Efficiency method used transfer variables from a list to the binding variable list without copying.
	 * @param freeVars The list of variables to transfer from. Will be emptied.
	 * @return True if there was a bound list to receive the elements. False otherwise.
	 */
	inline bool transferFreeVariables(ClauseList& freeVars) {
		if (mFreeVars) { mFreeVars->splice(mFreeVars->end(), freeVars); }
		else freeVars.clear();
		return (bool)mFreeVars;
	}

	/**
	 * Efficiency method used transfer clauses from a list to the binding clause list without copying.
	 * @param extraClauses The list of clauses to transfer from. Will be emptied.
	 * @return True if there was a bound list to receive the elements. False otherwise.
	 */
	inline bool transferExtraClauses(ClauseList& extraClauses) {
		if (mExtraClauses) { mExtraClauses->splice(mExtraClauses->end(), extraClauses); }
		else extraClauses.clear();
		return (bool)mExtraClauses;
	}



	/// Convenience method for constructing a new context corresponding
	/// to a formula occurring within the scope of an additional negation.
	inline Context mkNegated() const { return Context(mPos, mPart, *mTime, TRUE_STR, mExtraClauses, mFreeVars, true, !mPositive, mPreStmts); }

	/// Convenience method for constructing a new context corresponding
	/// to an atom taking a specific value.
	/// @param value The value the atom should take.
	inline Context mkValue(std::string const& value) const { return Context(mPos, mPart, *mTime, value, mExtraClauses, mFreeVars, mNeg, mPositive, mPreStmts); }

	/// Convenience method for constructing a new context corresponding
	/// to a formula at a new position.
	/// @param pos The new position the formula is at.
	inline Context mkPos(Position pos) const { return Context(pos, mPart, *mTime, TRUE_STR, mExtraClauses, mFreeVars, mNeg, mPositive, mPreStmts); }

	/// Convenience method for constructing a new context with a separate timestamp.
	/// @param timestamp The new timestamp for the formula context.
	inline Context mkTime(std::string const& timestamp) const { return Context(mPos, mPart, timestamp, TRUE_STR, mExtraClauses, mFreeVars, mNeg, mPositive, mPreStmts); }

	inline Context mkIncPart(IPart ipart) const { return Context(mPos, ipart, *mTime, TRUE_STR, mExtraClauses, mFreeVars, mNeg, mPositive, mPreStmts); }

	/// Convenience method for constructing a new context that captures free variables.
	/// @param freeVars The list to capture the free variables in.
	inline Context mkBindVars(ClauseList* freeVars)	const {  return Context(mPos, mPart, *mTime, TRUE_STR, mExtraClauses, freeVars , mNeg, mPositive, mPreStmts); }

	/// Convenience method for constructing a new context that captures extra clauses
	/// @param extraClauses The list to capture the extra clauses in.
	inline Context mkBindClauses(ClauseList* extraClauses) const {  return Context(mPos, mPart, *mTime, TRUE_STR, extraClauses, mFreeVars, mNeg, mPositive, mPreStmts); }


	/// Copy Operator
	inline Context const& operator=(Context const& other) { return copy(other); }

	/// Copy another context
	Context const& copy(Context const& other);
};


#endif
