within Dynawo.Electrical.StaticVarCompensators;

/*
* Copyright (c) 2021, RTE (http://www.rte-france.com)
* See AUTHORS.txt
* All rights reserved.
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, you can obtain one at http://mozilla.org/MPL/2.0/.
* SPDX-License-Identifier: MPL-2.0
*
* This file is part of Dynawo, an hybrid C++/Modelica open source suite of simulation tools for power systems.
*/

model SVarCPVProp "PV static var compensator model with slope without mode handling"
  import Modelica;
  import Dynawo.Types;
  import Dynawo.Connectors;
  import Dynawo.Electrical.Controls.Basics.SwitchOff;

  extends AdditionalIcons.SVarC;
  extends SwitchOff.SwitchOffShunt;

  Connectors.ACPower terminal(V(re(start = u0Pu.re), im(start = u0Pu.im)), i(re(start = i0Pu.re), im(start = i0Pu.im))) "Connector used to connect the static var compensator to the grid";

  parameter Types.PerUnit BMaxPu "Maximum value for the variable susceptance in p.u (base UNom, SnRef)";
  parameter Types.PerUnit BMinPu "Minimum value for the variable susceptance in p.u (base UNom, SnRef)";
  parameter Types.PerUnit LambdaPu "Statism of the regulation law URefPu = UPu + LambdaPu*QPu in p.u (base UNom, SnRef)";
  parameter Types.PerUnit BShuntPu "Fixed susceptance of the static var compensator in p.u (for standby mode) (base UNom, SnRef)";
  parameter Types.VoltageModule UNom "Static var compensator nominal voltage in kV";
  parameter Types.VoltageModulePu URef0Pu "Start value of the voltage regulation set point in p.u (base UNom)";

  input Types.VoltageModule URefPu(start = URef0Pu) "Voltage reference for the regulation in kV";

  Types.PerUnit BVarRawPu(start = BVar0Pu) "Raw variable susceptance of the static var compensator in p.u (base UNom, SnRef)";
  Types.PerUnit BVarPu(start = BVar0Pu) "Variable susceptance of the static var compensator in p.u (base UNom, SnRef)";
  Types.PerUnit BPu(start = B0Pu) "Susceptance of the static var compensator in p.u (base UNom, SnRef)";
  Types.VoltageModulePu UPu(start = U0Pu) "Voltage amplitude at terminal in p.u (base UNom)";
  Types.ReactivePowerPu QInjPu(start = B0Pu * U0Pu ^ 2) "Reactive power in p.u (base SnRef) (generator convention)";
  Types.ActivePowerPu PInjPu(start = 0) "Active power in p.u (base SnRef) (generator convention)";

protected
  parameter Types.PerUnit B0Pu "Start value of the susceptance in p.u (base UNom, SnRef)";
  parameter Types.VoltageModulePu U0Pu "Start value of voltage amplitude at injector terminal in p.u (base UNom)";
  parameter Types.ComplexVoltagePu u0Pu "Start value of complex voltage at injector terminal in p.u (base UNom)";
  parameter Types.ComplexCurrentPu i0Pu "Start value of complex current at injector terminal in p.u (base UNom, SnRef) (receptor convention)";
  final parameter Types.PerUnit BVar0Pu = B0Pu - BShuntPu "Start value of variable susceptance in p.u (base UNom, SnRef)";

equation
  URefPu = UPu + LambdaPu * (BVarRawPu + BShuntPu) * UPu ^ 2;
  BVarPu = if BVarRawPu > BMaxPu then BMaxPu elseif BVarRawPu < BMinPu then BMinPu else BVarRawPu;

  if (running.value) then
    terminal.i = terminal.V * Complex(0, BPu);
    UPu = Modelica.ComplexMath.'abs'(terminal.V);
    BPu = BVarPu + BShuntPu;
  else
    terminal.i = Complex(0);
    UPu = 0.;
    BPu = 0.;
  end if;

  PInjPu = 0;
  QInjPu = - ComplexMath.imag(terminal.V * ComplexMath.conj(terminal.i));

  annotation(preferredView = "text");
end SVarCPVProp;
