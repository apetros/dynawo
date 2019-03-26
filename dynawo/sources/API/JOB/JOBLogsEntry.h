//
// Copyright (c) 2015-2019, RTE (http://www.rte-france.com)
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

/**
 * @file JOBLogsEntry.h
 * @brief logs entries description : interface file
 *
 */

#ifndef API_JOB_JOBLOGSENTRY_H_
#define API_JOB_JOBLOGSENTRY_H_

#include <string>
#include <vector>

#include "JOBExport.h"

namespace job {
class AppenderEntry;

/**
 * @class LogsEntry
 * @brief Logs entries container class
 */
class __DYNAWO_JOB_EXPORT LogsEntry {
 public:
  /**
   * @brief Destructor
   */
  virtual ~LogsEntry() {}

  /**
   * @brief Appender entry adder
   * @param appenderEntry : appender for the job
   */
  virtual void addAppenderEntry(const boost::shared_ptr<AppenderEntry> & appenderEntry) = 0;

  /**
   * @brief Appender entries getter
   * @return Vector of the appenders for the job
   */
  virtual std::vector<boost::shared_ptr<AppenderEntry> > getAppenderEntries() const = 0;

  class Impl;  ///< implemented class
};

}  // namespace job

#endif  // API_JOB_JOBLOGSENTRY_H_
