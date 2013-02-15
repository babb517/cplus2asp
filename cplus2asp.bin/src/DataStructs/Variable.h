#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "Sort.h"
#include "Constant.h"
#include "Element.h"


/**
 * Represents a C+ variable, an element that can stand for any value of a certain sort.
 */
class Variable : public Element
{
private:
	Sort const* mSortRef; 				///< Reference to the sort that this variable represents.

public:
	
	/**
	 * Full constructor.
	 * @param name - The C+ name of the variable.
	 * @param sort - The sort that the variable is associated with.
	 */
	Variable(std::string const& name, Sort const* sort = NULL);


	inline virtual std::string const& fullName() const		{ return baseName(); }
	inline virtual std::string const& fullTransName() const	{ return baseTransName(); }
	virtual std::string toString() const;
	inline virtual bool isNumeric() const 					{ return domain() && domain()->isNumeric(); }
	inline virtual bool isBoolean() const 					{ return domain() && domain()->isBoolean(); }
	inline virtual bool isStarred() const 					{ return domain() && domain()->isStarred(); }
	
	/// Gets the sort the variable is associated with.
	inline Sort const* domain() const 						{ return mSortRef; }

	/// Sets the domain that this variable ranges over.
	inline void domain(Sort const* domain)					{ mSortRef = domain; }


	/// Sets the sort the variable is associated with.
	inline void setDomain(Sort* sort) 						{ mSortRef = sort; }

	/// Determines if this variable ranges over action constants.
	inline bool isActionVariable() const					{ return domain() && domain()->isActionSort(); }

	/// Determines if this variable ranges over fluent constants.
	inline bool isFluentVariable() const					{ return domain() && domain()->isFluentSort(); }

	/// Determines if this variable ranges over static abnormality constants.
	inline bool isStaticAbnormalityVariable() const			{ return domain() && domain()->isStaticAbnormalitySort(); }

	/// Determines if this variable ranges over dynamic abnormality constants.
	inline bool isDynamicAbnormalityVariable() const		{ return domain() && domain()->isDynamicAbnormalitySort(); }

	/// Determines if this variable ranges over rigid constants.
	inline bool isRigidVariable() const						{ return domain() && domain()->isRigidSort(); }

	/// Determines if this variable ranges over constants.
	inline bool isConstantVariable() const					{ return domain() && domain()->isConstantSort(); }

	/// Determines the constant type that this variable ranges over. (Or NULL if this variable isn't a constant variable.
	inline Constant::ConstantType getConstantType() const	{ return (domain()) ? domain()->getConstantType(): Constant::CONST_UNKNOWN; }


	/**
	 * Destructor.
	 */
	inline virtual ~Variable() 								{ /* Intentionally Left Blank */ }
};

#endif /* VARIABLE_H */
