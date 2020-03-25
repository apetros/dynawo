//
// Copyright (c) 2015-2020, RTE (http://www.rte-france.com)
// See AUTHORS.txt
// All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, you can obtain one at http://mozilla.org/MPL/2.0/.
// SPDX-License-Identifier: MPL-2.0
//
// This file is part of Dynawo, an hybrid C++/Modelica open source time domain
// simulation tool for power systems.
//

#include "CRTCriteriaParamsFactory.h"
#include "CRTCriteriaParamsImpl.h"

using boost::shared_ptr;

namespace criteria {

shared_ptr<CriteriaParams>
CriteriaParamsFactory::newCriteriaParams() {
  return shared_ptr<CriteriaParams>(new CriteriaParams::Impl());
}

}  // namespace criteria
