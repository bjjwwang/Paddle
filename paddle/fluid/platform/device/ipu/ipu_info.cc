/* Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#include "paddle/fluid/platform/device/ipu/ipu_info.h"
#include "paddle/fluid/platform/device/ipu/ipu_backend.h"

namespace paddle {
namespace platform {

//! Get a list of device ids from environment variable or use all.
std::vector<int> GetSelectedIPUDevices() {
  std::shared_ptr<platform::ipu::IpuBackend> ipu_backend =
      platform::ipu::IpuBackend::GetInstance();
  return ipu_backend->GetDeviceIds();
}

//! Get the total number of IPU devices in system.
int GetIPUDeviceCount() {
  std::shared_ptr<platform::ipu::IpuBackend> ipu_backend =
      platform::ipu::IpuBackend::GetInstance();
  return ipu_backend->GetNumDevices();
}
}  // namespace platform
}  // namespace paddle
