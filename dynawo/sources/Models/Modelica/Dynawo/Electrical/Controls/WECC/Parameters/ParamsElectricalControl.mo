within Dynawo.Electrical.Controls.WECC.Parameters;

/*
* Copyright (c) 2023, RTE (http://www.rte-france.com)
* See AUTHORS.txt
* All rights reserved.
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, you can obtain one at http://mozilla.org/MPL/2.0/.
* SPDX-License-Identifier: MPL-2.0
*
* This file is part of Dynawo, an hybrid C++/Modelica open source suite
* of simulation tools for power systems.
*/

record ParamsElectricalControl
  parameter Boolean QFlag "Q control flag: const. pf or Q ctrl (0) or voltage/Q (1)" annotation(Dialog(tab="Electrical Control"));
  parameter Boolean VFlag "Voltage control flag: voltage control (0) or Q ctrl (1)" annotation(Dialog(tab="Electrical Control"));
  parameter Boolean PfFlag "Power factor flag: Q control (0) or pf control(1)" annotation(Dialog(tab="Electrical Control"));
  parameter Boolean PPriority "Q/P priority: Q priority (0) or P priority (1)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.Time tRv "Filter time constant terminal voltage in s(typical: 0.01..0.02)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit UMinPu "Low voltage condition trigger voltage for FRT in pu (base UNom) (typical: 0..0.9)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit UMaxPu "High voltage condition trigger voltage for FRT in pu (base UNom) (typical: 1.1..1.3)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit VRef0Pu "Reference voltage for reactive current injection in pu (base UNom) (typical: 0.95..1.05)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit Dbd1 "Overvoltage deadband for reactive current injection (typical: -0.1..0)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit Dbd2 "Undervoltage deadband for reactive current injection (typical: 0..0.1)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit Kqv "K-Factor, reactive current injection gain (typical: 0..10)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit Iqh1Pu "Maximum reactive current injection (typical: 1..1.1) in pu (base UNom, SNom)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit Iql1Pu "Minimum reactive current injection (typical: -1.1..-1) in pu (base UNom, SNom)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.Time tP "Filter time constant active power in s (typical: 0.1..0.2)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit QMaxPu "Reactive power upper limit, when vFlag == 1 in pu (base SNom)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit QMinPu "Reactive power lower limit, when vFlag == 1 in pu (base SNom)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit Kqp "Proportional gain local reactive power PI controller" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit Kqi "Integrator gain local reactive power PI controller" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit VMaxPu "Maximum voltage at inverter terminal in pu (base UNom) (typical: 1.05..1.15)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit VMinPu "Minimum voltage at inverter terminal in pu (base UNom) (typical: 0.85..0.95)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit Kvp "Proportional gain local Voltage PI controller" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit Kvi "Integrator gain local Voltage PI controller" annotation(Dialog(tab="Electrical Control"));
  parameter Types.Time Tiq "Filter time constant reactive current in s(typical: 0.01..0.02)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.Time tPord "Filter time constant inverter active power in s" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit PMaxPu "Active power upper limit in pu (base SNom) (typical: 1)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit PMinPu "Active power lower limit in pu (base SNom) (typical: 0)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit DPMax "Active power upper rate limit" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit DPMin "Active power lower rate limit" annotation(Dialog(tab="Electrical Control"));
  parameter Types.PerUnit IMaxPu "Maximal apparent current magnitude in pu (base UNom, SNom)" annotation(Dialog(tab="Electrical Control"));
  parameter Types.ActivePowerPu PInj0Pu "Start value of active power at injector terminal in pu (generator convention) (base SNom)";
  parameter Types.ReactivePowerPu QInj0Pu "Start value of reactive power at injector terminal in pu (generator convention) (base SNom)";
  parameter Types.VoltageModulePu UInj0Pu "Start value of voltage magnitude at injector terminal in pu (base UNom)";
  parameter Types.PerUnit PF0 "Start value of powerfactor";
  parameter Types.CurrentModulePu Id0Pu "Start value of d-component current at injector terminal in pu (generator convention) (base SNom, UNom)";
  parameter Types.CurrentModulePu Iq0Pu "Start value of q-component current at injector terminal in pu (generator convention) (base SNom, UNom)";

  annotation(preferredView = "text");
end ParamsElectricalControl;
