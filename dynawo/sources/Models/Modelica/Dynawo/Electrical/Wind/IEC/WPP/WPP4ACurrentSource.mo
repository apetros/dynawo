within Dynawo.Electrical.Wind.IEC.WPP;

/*
* Copyright (c) 2023, RTE (http://www.rte-france.com)
* See AUTHORS.txt
* All rights reserved.
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, you can obtain one at http://mozilla.org/MPL/2.0/.
* SPDX-License-Identifier: MPL-2.0
*
* This file is part of Dynawo, an hybrid C++/Modelica open source suite of simulation tools for power systems.
*/

model WPP4ACurrentSource "Wind Power Plant Type 4A model from IEC 61400-27-1 standard : WT4A, communication modules"
  extends Dynawo.Electrical.Wind.IEC.BaseClasses.BaseWPP;

  //PControl parameters
  parameter Types.PerUnit DPMaxP4APu "Maximum WT power ramp rate in pu/s (base SNom) (generator convention)" annotation(
    Dialog(tab = "PControl"));
  parameter Types.PerUnit DPRefMax4APu "Maximum WT reference power ramp rate in pu/s (base SNom) (generator convention)" annotation(
    Dialog(tab = "PControl"));
  parameter Types.PerUnit DPRefMin4APu "Minimum WT reference power ramp rate in pu/s (base SNom) (generator convention)" annotation(
    Dialog(tab = "PControl"));
  parameter Types.Time tPOrdP4A "Power order lag time constant in s" annotation(
    Dialog(tab = "PControl"));
  parameter Types.Time tPWTRef4A "Reference power order lag time constant in s" annotation(
    Dialog(tab = "PControl"));

  Dynawo.Electrical.Wind.IEC.WT.WT4ACurrentSource wT4ACurrentSource(BesPu = BesPu, DPMaxP4APu = DPMaxP4APu, DPRefMax4APu = DPRefMax4APu, DPRefMin4APu = DPRefMin4APu, DUdb1Pu = DUdb1Pu, DUdb2Pu = DUdb2Pu, DfcMaxPu = DfcMaxPu, DfpMaxPu = DfpMaxPu, DipMaxPu = DipMaxPu, DiqMaxPu = DiqMaxPu, DiqMinPu = DiqMinPu, GesPu = GesPu, IGsIm0Pu = IGsIm0Pu, IGsRe0Pu = IGsRe0Pu, IMaxDipPu = IMaxDipPu, IMaxPu = IMaxPu, IpMax0Pu = IpMax0Pu, IqH1Pu = IqH1Pu, IqMax0Pu = IqMax0Pu, IqMaxPu = IqMaxPu, IqMin0Pu = IqMin0Pu, IqMinPu = IqMinPu, IqPostPu = IqPostPu, Kipaw = Kipaw, Kiq = Kiq, Kiqaw = Kiqaw, Kiu = Kiu, Kpaw = Kpaw, Kpq = Kpq, Kpqu = Kpqu, Kpu = Kpu, Kpufrt = Kpufrt, Kqv = Kqv, MdfsLim = MdfsLim, MpUScale = MpUScale, MqG = MqG, Mqfrt = Mqfrt, Mqpri = Mqpri, P0Pu = P0Pu, PAg0Pu = PAg0Pu, Q0Pu = Q0Pu, QMax0Pu = QMax0Pu, QMaxPu = QMaxPu, QMin0Pu = QMin0Pu, QMinPu = QMinPu, QlConst = QlConst, RDropPu = RDropPu, ResPu = ResPu, SNom = SNom, U0Pu = U0Pu, UGsIm0Pu = UGsIm0Pu, UGsRe0Pu = UGsRe0Pu, UMaxPu = UMaxPu, UMinPu = UMinPu, UOverPu = UOverPu, UPhase0 = UPhase0, UPll1Pu = UPll1Pu, UPll2Pu = UPll2Pu, URef0Pu = URef0Pu, UUnderPu = UUnderPu, UpDipPu = UpDipPu, UpquMaxPu = UpquMaxPu, UqDipPu = UqDipPu, UqRisePu = UqRisePu, XDropPu = XDropPu, XWT0Pu = XWT0Pu, XesPu = XesPu, fOverPu = fOverPu, fUnderPu = fUnderPu, TabletUoverUwtfilt11= TabletUoverUwtfilt11, TabletUoverUwtfilt12 = TabletUoverUwtfilt12, TabletUoverUwtfilt21 = TabletUoverUwtfilt21, TabletUoverUwtfilt22 = TabletUoverUwtfilt22, TabletUoverUwtfilt31 = TabletUoverUwtfilt31, TabletUoverUwtfilt32 = TabletUoverUwtfilt32, TabletUoverUwtfilt = TabletUoverUwtfilt, TabletUunderUwtfilt11 = TabletUunderUwtfilt11, TabletUunderUwtfilt12 = TabletUunderUwtfilt12, TabletUunderUwtfilt21 = TabletUunderUwtfilt21, TabletUunderUwtfilt22 = TabletUunderUwtfilt22, TabletUunderUwtfilt31 = TabletUunderUwtfilt31, TabletUunderUwtfilt32 = TabletUunderUwtfilt32, TabletUunderUwtfilt = TabletUunderUwtfilt, Tabletfoverfwtfilt11 = Tabletfoverfwtfilt11, Tabletfoverfwtfilt12 = Tabletfoverfwtfilt12, Tabletfoverfwtfilt21 = Tabletfoverfwtfilt21, Tabletfoverfwtfilt22 = Tabletfoverfwtfilt22, Tabletfoverfwtfilt31 = Tabletfoverfwtfilt31, Tabletfoverfwtfilt32 = Tabletfoverfwtfilt32, Tabletfoverfwtfilt = Tabletfoverfwtfilt, Tabletfunderfwtfilt11 = Tabletfunderfwtfilt11, Tabletfunderfwtfilt12 = Tabletfunderfwtfilt12, Tabletfunderfwtfilt21 = Tabletfunderfwtfilt21, Tabletfunderfwtfilt22 = Tabletfunderfwtfilt22, Tabletfunderfwtfilt31 = Tabletfunderfwtfilt31, Tabletfunderfwtfilt32 = Tabletfunderfwtfilt32, Tabletfunderfwtfilt = Tabletfunderfwtfilt, i0Pu = i0Pu, tG = tG, tIcFilt = tIcFilt, tIpFilt = tIpFilt, tPOrdP4A = tPOrdP4A, tPWTRef4A = tPWTRef4A, tPcFilt = tPcFilt, tPll = tPll, tPost = tPost, tPpFilt = tPpFilt, tQcFilt = tQcFilt, tQord = tQord, tQpFilt = tQpFilt, tS = tS, tUcFilt = tUcFilt, tUpFilt = tUpFilt, tUss = tUss, tfcFilt = tfcFilt, tfpFilt = tfpFilt, u0Pu = u0Pu) annotation(
    Placement(visible = true, transformation(origin = {20, 0}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));

equation
  connect(wT4ACurrentSource.terminal, elecMeasurements.terminal1) annotation(
    Line(points = {{42, 0}, {58, 0}}, color = {0, 0, 255}));
  connect(tanPhi, wT4ACurrentSource.tanPhi) annotation(
    Line(points = {{-20, 120}, {-20, 12}, {-2, 12}}, color = {0, 0, 127}));
  connect(wPPControl.PPDRefComPu, wT4ACurrentSource.PWTRefPu) annotation(
    Line(points = {{-38, 8}, {-20, 8}, {-20, 4}, {-2, 4}}, color = {0, 0, 127}));
  connect(wPPControl.xPDRefComPu, wT4ACurrentSource.xWTRefPu) annotation(
    Line(points = {{-38, -8}, {-20, -8}, {-20, -4}, {-2, -4}}, color = {0, 0, 127}));
  connect(omegaRefPu, wT4ACurrentSource.omegaRefPu) annotation(
    Line(points = {{-140, -40}, {-20, -40}, {-20, -12}, {-2, -12}}, color = {0, 0, 127}));

  annotation(
    preferredView = "diagram",
    Icon(graphics = {Text(origin = {70, -1}, extent = {{-36, 16}, {36, -16}}, textString = "A")}));
end WPP4ACurrentSource;
