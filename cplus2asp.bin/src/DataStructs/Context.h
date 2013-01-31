#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>

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

	/// The incremental module that a statement is associated with.
	enum IPart { BASE, CUMULATIVE, VOLATILE, NONE };

private:
	Position mPos;				///< The location which the expression occurs within the program.
	IPart mPart;				///< The incremental module we are currently working in.
	bool mNeg; 					///< Whether this expression occurs in the scope of one or more negations.
	bool mPositive;				///< Whether this expression occurs in the scope of an _even_ number of negations.
	std::string const& mVal;	///< The value that the expression should take (where applicable).
	std::string const& mTime;	///< The timestamp to be applied to the expression (where applicable).


	static std::string const EMPTY_STR;		///< Concrete empty string used to instantiate empty references.

public:

	/**
	 * Basic constructor used for the context for an expression.
	 * @param pos - The position that the formula is located in.
	 * @param ipart - The incremental module the statement is associated with.
	 * @param negated - Whether this formula occurs in the scope of one or more negations.
	 * @param positive - Whether this formula occurs in the scope of an _even_ number of negations.
	 */
	inline Context(Position pos, IPart ipart, std::string const& timestamp, bool negated = false, bool positive = true)
		: mPos(pos), mPart(ipart), mNeg(negated), mPositive(positive), mVal(EMPTY_STR), mTime(timestamp)
		{ /* Intentionally Left Blank */}

	/**
	 * Basic constructor used for the context for an atom.
	 * @param pos - The position that the formula is located in.
	 * @param ipart - The incremental module the statement is associated with.
	 * @param value - The value which the atom should take.
	 * @param negated - Whether this formula occurs in the scope of one or more negations.
	 * @param positive - Whether this formula occurs in the scope of an _even_ number of negations.
	 */
	inline Context(Position pos, IPart ipart, std::string const& timestamp, std::string const& value, bool negated = false, bool positive = true)
		: mPos(pos), mPart(ipart), mNeg(negated), mPositive(positive), mVal(value), mTime(timestamp)
		{ /* Intentionally Left Blank */}


	/// Basic destructor. Does nothing.
	inline virtual ~Context() { /* Intentionally Left Blank */ }

	/// Determines whether the formula occurs in the head of a rule.
	inline Position getPos() const { return mPos; }

	/// Determines whether the formula occurs within the scope of negation.
	inline bool getNegated() const { return mNeg; }

	/// Determines whether the formula occurs within an even number of negations.
	inline bool getPositive() const { return mPositive; }

	/// Determines the timestamp which should be applied to the formula
	inline std::string const& getTimestamp() const { return mTime; }

	/// Determines the value which the formula should be set equal to.
	inline std::string const& getValue() const { return mVal; }

	/// Convenience method for constructing a new context corresponding
	/// to a formula occurring within the scope of an additional negation.
	inline Context mkNegated() const { return Context(mPos, mPart, mTime, EMPTY_STR, true, !mPositive); }

	/// Convenience method for constructing a new context corresponding
	/// to an atom taking a specific value.
	/// @param value The value the atom should take.
	inline Context mkValue(std::string const& value) const { return Context(mPos, mPart, mTime, value, mNeg, mPositive); }

	/// Convenience method for constructing a new context corresponding
	/// to a formula at a new position.
	/// @param pos The new position the formula is at.
	inline Context mkPos(Position pos) const { return Context(pos, mPart, mTime, EMPTY_STR, mNeg, mPositive); }

	/// Convenience method for constucting a new context with a separate timestamp.
	/// @param timestamp The new timestamp for the formula context.
	inline Context mkTime(std::string const& timestamp) const { return Context(mPos, mPart, timestamp, EMPTY_STR, mNeg, mPositive); }

	inline Context mkIncPart(IPart ipart) const { return Context(mPos, ipart, mTime, EMPTY_STR, mNeg, mPositive); }

};


#endif
