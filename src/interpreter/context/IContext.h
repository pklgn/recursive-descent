#pragma once

#include <string>

#include "../common_interpreter.h"
#include "../expression/IExpression_fwd.h"
#include "IContext_fwd.h"

namespace interpreter::context
{

/*
Контекст, используемый IExpression
*/
template <typename T>
class IContext
{
public:
	using IExpression = expression::IExpressionSharedPtr;

	virtual bool Lookup(const Terminal& name) const = 0;
	virtual void Assign(const IExpression&, const T&) = 0;

	virtual ~IContext() = default;
};

} // namespace interpreter::context
