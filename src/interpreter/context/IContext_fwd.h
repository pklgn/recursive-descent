#pragma once

#include <memory>

namespace interpreter::context
{

class IContext;

using IContextRawPtr = IContext*;

using IContextPtr = std::unique_ptr<IContext>;
using IContextSharedPtr = std::shared_ptr<IContext>;
using IContextWeakPtr = std::weak_ptr<IContext>;

} // namespace interpreter::context
