#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
#include "Constant.h"

/**
 * Subclass of Constant designed to represent an attribute declaration.
 * Contains additional information that connects an attribute to its action.
 */
class Attribute : public Constant
{
private:
	Constant const* mParent; 			///< Reference to the constant (action) this attribute binds to.
public:
	

	/**
	 * Full constructor.
	 * @param name - The C+ name of this constant.
	 * @param domain - The sort which this constant ranges over.
	 * @param parent - The constant which this is an attribute of
	 * @param params - A list of parameters for the constant. NULL indicates that there are no parameters.
	 */
	inline Attribute(std::string const& name, Sort  const* domain, Constant const* parent, ConstSortList const* params = NULL)
		: Constant(name, domain, Constant::CONST_ATTRIBUTE, params), mParent(parent)
	{ /* Intentionally Left Blank */ }
	
	virtual std::string toString() const;
	
	/// Retrieves the parent constant for this attribute.
	inline Constant const* parent() const { return mParent; }

	/// Sets the parent constant for this attribute
	inline void parent(Constant const* parent) { mParent = parent; }

	/**
	 * Destructor.
	 */
	inline virtual ~Attribute() { /* Intentionally Left Blank */ }
};

#endif // ATTRIBUTE_H
