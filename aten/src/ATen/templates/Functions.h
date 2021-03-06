#pragma once

// ${generated_comment}

#include "ATen/core/Scalar.h"
#include "ATen/Type.h"
#include "ATen/TypeExtendedInterface.h"
#include "ATen/Tensor.h"
#include "ATen/core/Storage.h"
#include "ATen/core/Generator.h"
#include "ATen/core/Deprecated.h"
#include "ATen/NativeFunctions.h"
#include "ATen/DeviceGuard.h"
#include "ATen/core/TensorOptions.h"
#include "ATen/core/Reduction.h"

namespace at {

using native::from_blob;
using native::tensor;

${function_declarations}

namespace detail {

static inline TypeExtendedInterface & infer_type(const Tensor & t) {
  AT_CHECK(t.defined(), "undefined Tensor");
  return static_cast<TypeExtendedInterface&>(t.type());
}
static inline TypeExtendedInterface & infer_type(const TensorList & tl) {
  AT_CHECK(tl.size() > 0, "expected a non-empty list of Tensors");
  return static_cast<TypeExtendedInterface&>(tl[0].type());
}
static inline TypeExtendedInterface & non_specific_type() {
  return static_cast<TypeExtendedInterface&>(at::getNonVariableType(at::Backend::Undefined, at::ScalarType::Float));
}

} // namespace detail

// function definitions are all static inline because
// they are one-line statically dispatched functions that
// invoke the actual dynamic dispatch on the correct argument
${function_definitions}

}
