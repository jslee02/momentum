/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "momentum/common/progress_bar.h"

namespace momentum {

ProgressBar::ProgressBar(const std::string& name, const int64_t numOperations) {
  using namespace indicators;

  bar_.set_option(option::BarWidth(kMaxWidth - name.size() - 9));
  bar_.set_option(option::MaxProgress(numOperations));
  bar_.set_option(option::Start{"["});
  bar_.set_option(option::Fill{"="});
  bar_.set_option(option::Lead{">"});
  bar_.set_option(option::Remainder{" "});
  bar_.set_option(option::End{"]"});
  bar_.set_option(option::PrefixText{name});
  bar_.set_option(option::ShowPercentage{true});
  bar_.set_option(option::FontStyles{std::vector<FontStyle>{FontStyle::bold}});
}

void ProgressBar::increment(int64_t count) {
  bar_.set_progress(bar_.current() + count);
}

void ProgressBar::set(int64_t count) {
  bar_.set_progress(count);
}

} // namespace momentum
