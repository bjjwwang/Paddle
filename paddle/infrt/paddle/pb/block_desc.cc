// Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "paddle/infrt/paddle/pb/block_desc.h"

namespace infrt::paddle::pb {

template <>
framework_proto::VarDesc* BlockDesc::GetVar<framework_proto::VarDesc>(
    int32_t idx) {
  CHECK_LT(idx, static_cast<int>(VarsSize())) << "idx >= vars.size()";
  return desc_->mutable_vars(idx);
}

template <>
framework_proto::VarDesc* BlockDesc::AddVar<framework_proto::VarDesc>() {
  return desc_->add_vars();
}

template <>
framework_proto::OpDesc* BlockDesc::GetOp<framework_proto::OpDesc>(
    int32_t idx) {
  CHECK_LT(idx, static_cast<int>(OpsSize())) << "idx >= ops.size()";
  return desc_->mutable_ops(idx);
}

template <>
framework_proto::OpDesc* BlockDesc::AddOp<framework_proto::OpDesc>() {
  return desc_->add_ops();
}

}  // namespace infrt::paddle::pb
