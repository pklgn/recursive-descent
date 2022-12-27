#pragma once

#include <memory>

namespace parser
{

class IParser;

using IExpressionRawPtr = IParser*;

using IExpressionPtr = std::unique_ptr<IParser>;
using IExpressionSharedPtr = std::shared_ptr<IParser>;
using IExpressionWeakPtr = std::weak_ptr<IParser>;

} // namespace parser
