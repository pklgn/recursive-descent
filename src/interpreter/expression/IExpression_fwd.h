#pragma once

#include <memory>

namespace interpreter::expression
{

class IExpression;

using IExpressionRawPtr = IExpression*;

using IExpressionPtr = std::unique_ptr<IExpression>;
using IExpressionSharedPtr = std::shared_ptr<IExpression>;
using IExpressionWeakPtr = std::weak_ptr<IExpression>;

} // namespace interpreter::expression
