within Dynawo.Electrical.Machines.SignalN;

/*
* Copyright (c) 2022, RTE (http://www.rte-france.com)
* See AUTHORS.txt
* All rights reserved.
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, you can obtain one at http://mozilla.org/MPL/2.0/.
* SPDX-License-Identifier: MPL-2.0
*
* This file is part of Dynawo, an hybrid C++/Modelica open source suite of simulation tools for power systems.
*/

model GeneratorPVRemoteDiagramPQSFR_INIT "Initialisation model for generator PV with a PQ diagram, based on SignalN for the frequency handling and a remote voltage regulation and that participates in the Secondary Frequency Regulation (SFR)"
  extends BaseClasses_INIT.BaseGeneratorSignalNPQDiagram_INIT;
  extends AdditionalIcons.Init;

  parameter Types.VoltageModulePu URef0 "Start value of the voltage regulation set point in pu (base UNom)";
  parameter Types.VoltageModulePu URegulated0 "Start value of the voltage regulated in pu (base UNom)";

equation
  if QGen0Pu <= QMin0Pu and URegulated0 >= URef0 then
    qStatus0 = QStatus.AbsorptionMax;
  elseif QGen0Pu >= QMax0Pu and URegulated0 <= URef0 then
    qStatus0 = QStatus.GenerationMax;
  else
    qStatus0 = QStatus.Standard;
  end if;

  annotation(preferredView = "text");
end GeneratorPVRemoteDiagramPQSFR_INIT;
