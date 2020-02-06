within Dynawo.Electrical.Transformers;

/*
* Copyright (c) 2015-2019, RTE (http://www.rte-france.com)
* See AUTHORS.txt
* All rights reserved.
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, you can obtain one at http://mozilla.org/MPL/2.0/.
* SPDX-License-Identifier: MPL-2.0
*
* This file is part of Dynawo, an hybrid C++/Modelica open source time domain simulation tool for power systems.
*/

package BaseClasses

record TransformerParameters "Classical transformer parameters"

  parameter Types.PerUnit RPu "Resistance of the generator transformer in p.u (base U2Nom, SnRef)";
  parameter Types.PerUnit BPu "Susceptance of the generator transformer in p.u (base U2Nom, SnRef)";
  parameter Types.PerUnit XPu "Reactance of the generator transformer in p.u (base U2Nom, SnRef)";
  parameter Types.PerUnit GPu "Conductance of the generator transformer in p.u (base U2Nom, SnRef)";

  final parameter Types.ComplexImpedancePu ZPu = Complex(RPu, XPu) "Impedance in p.u (base U2Nom, SnRef)";
  final parameter Types.ComplexAdmittancePu YPu = Complex(GPu, BPu) "Admittance in p.u (base U2Nom, SnRef)";

end TransformerParameters;

partial model BaseTransformer "Base model for transformer"

/*
  Equivalent circuit and conventions:

               I1  r                I2
    U1,P1,Q1 -->---oo----R+jX-------<-- U2,P2,Q2
  (terminal1)                   |      (terminal2)
                               G+jB
                                |
                               ---
*/
  import Dynawo.Electrical.Controls.Basics.SwitchOff;

  extends SwitchOff.SwitchOffTransformer;

equation
  if (running.value) then
    rTfoPu * rTfoPu * terminal1.V = rTfoPu * terminal2.V + ZPu * terminal1.i;
    terminal1.i = rTfoPu * (YPu * terminal2.V - terminal2.i);
  else
    terminal1.i = Complex (0);
    terminal2.i = Complex (0);
  end if;

end BaseTransformer;

end BaseClasses;