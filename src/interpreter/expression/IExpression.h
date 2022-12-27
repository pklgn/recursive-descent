#pragma once

#include <string>

#include "../common_interpreter.h"
#include "IExpression_fwd.h"

#include "../context/IContext.h"

namespace interpreter::expression
{

class IExpression
{
public:
	using Context = context::IContext;

	// TODO: const? noexept? constexpr?
	virtual IExpressionSharedPtr Copy() const = 0;
	virtual void Evaluate(Context& context) = 0; // TODO: shared_ptr/unique_ptr?
	virtual IExpressionSharedPtr Replace(const Terminal& name, const IExpressionSharedPtr& exp) const = 0;

	virtual ~IExpression() = default;
};

} // namespace interpreter::expression
