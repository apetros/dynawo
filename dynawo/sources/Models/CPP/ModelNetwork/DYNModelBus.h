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
 * @file  DYNModelBus.h
 *
 * @brief
 *
 */

#ifndef MODELS_CPP_MODELNETWORK_DYNMODELBUS_H_
#define MODELS_CPP_MODELNETWORK_DYNMODELBUS_H_

#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include "DYNNetworkComponentImpl.h"

namespace DYN {
class SubNetwork;  ///< AC-connected network
class BusInterface;
class BusDerivatives;
class ModelSwitch;
class ModelVoltageLevel;

/**
 * class ModelBus
 */
class ModelBus : public NetworkComponent::Impl {  ///< Generic AC network bus
 public:
  /**
   * @brief default constructor
   * @param bus: bus data interface to use for the model
   */
  explicit ModelBus(const boost::shared_ptr<BusInterface>& bus);

  /**
   * @brief destructor
   */
  ~ModelBus() { }

  /**
   * @brief calculated variables type
   */
  typedef enum {
    upuNum_ = 0,
    phipuNum_ = 1,
    uNum_ = 2,
    phiNum_ = 3,
    nbCalculatedVariables_ = 4
  } CalculatedVariables_t;

  /**
   * @brief index variable type
   */
  typedef enum {
    urNum_ = 0,
    uiNum_ = 1,
    irNum_ = 2,
    iiNum_ = 3
  } IndexVariable_t;

  /**
   * @brief add a bus to the neighbors
   * @param bus bus to add
   */
  void addNeighbor(boost::shared_ptr<ModelBus>& bus);  // add a bus to the neighbors (i.e. AC-connected) list

  /**
   * @brief clear neighbors
   * reset the list of neighbors
   */
  void clearNeighbors() {
    neighbors_.clear();
  }

  /**
   * @brief define variables
   * @param variables
   */
  static void defineVariables(std::vector<boost::shared_ptr<Variable> >& variables);

  /**
   * @brief instantiate variables
   * @param variables
   */
  void instantiateVariables(std::vector<boost::shared_ptr<Variable> >& variables);

  /**
   * @brief define parameters
   * @param parameters: vector to fill with the generic parameters
   */
  static void defineParameters(std::vector<ParameterModeler>& parameters);

  /**
   * @brief define non generic parameters
   * @param parameters: vector to fill with the non generic parameters
   */
  void defineNonGenericParameters(std::vector<ParameterModeler>& parameters);

  /**
   * @brief define elements
   * @param elements
   * @param mapElement map of elements
   */
  void defineElements(std::vector<Element>& elements, std::map<std::string, int>& mapElement);

  /**
   * @brief evaluate node injection
   *
   */
  void evalNodeInjection() { /* not needed */ }

  /**
   * @brief reset node injection
   */
  void resetNodeInjection();

  /**
   * @brief evaluate derivatives
   */
  void evalDerivatives();

  /**
   * @brief evaluate F
   */
  void evalF();

  /**
   * @brief compute the local Z function
   * @param t time
   */
  void evalZ(const double& t);

  /**
   * @brief compute the local G function
   * @param t time
   */
  void evalG(const double& t);

  /**
   * @brief evaluate calculated variables (for outputs)
   */
  void evalCalculatedVars();

  /**
   * @brief get the index of variables used to define the Jacobian associated to a calculated variable
   *
   * @param numCalculatedVar index of the calculated variable
   *
   * @param numVars index of variables used to define the Jacobian
   */
  void getDefJCalculatedVarI(int numCalculatedVar, std::vector<int>& numVars);

  /**
   * @brief evaluate the Jacobian associated to a calculated variable
   *
   * @param numCalculatedVar index of the calculated variable
   * @param y value of the variable used to calculate the Jacobian
   * @param yp value of the derivatives of variable used to calculate the Jacobian
   * @param res values of the Jacobian
   */
  void evalJCalculatedVarI(int numCalculatedVar, double* y, double* yp, std::vector<double>& res);

  /**
   * @brief evaluate the value of a calculated variable
   *
   * @param numCalculatedVar index of the calculated variable
   * @param y values of the variables used to calculate the variable
   * @param yp values of the derivatives used to calculate the variable
   *
   * @return value of the calculated variable
   */
  double evalCalculatedVarI(int numCalculatedVar, double* y, double* yp);

  /**
   * @copydoc NetworkComponent::evalYType()
   */
  void evalYType();

  /**
   * @copydoc NetworkComponent::evalFType()
   */
  void evalFType();

  void evalYMat() { /* not needed*/ }

  void init(int & yNum);

  /**
   * @copydoc NetworkComponent::Impl::getY0()
   */
  void getY0();

  /**
   * @copydoc NetworkComponent::Impl::setSubModelParameters(const boost::unordered_map<std::string, ParameterModeler>& params)
   */
  void setSubModelParameters(const boost::unordered_map<std::string, ParameterModeler>& params);

  /**
   * @copydoc NetworkComponent::setFequations( std::map<int, std::string> & fEquationIndex)
   */
  void setFequations(std::map<int, std::string>& fEquationIndex);

  /**
   * @copydoc NetworkComponent::setGequations( std::map<int,std::string>& gEquationIndex )
   */
  void setGequations(std::map<int, std::string>& gEquationIndex);

  /**
   * @brief evaluate state
   * @param time
   * @return state change type
   */
  NetworkComponent::StateChange_t evalState(const double& time);

  /**
   * @brief addBusNeighbors
   */
  void addBusNeighbors() { /* not needed*/ }

  /**
   * @brief init size
   */
  void initSize();

  /**
   * @brief add a new real current to the sum of real currents
   * @param ir new real current to add to the sum of real current
   */
  void irAdd(const double& ir);

  /**
   * @brief add a new imaginary current to the sum of imaginary currents
   * @param ii new imaginary current to add to the sum of imaginary currents
   */
  void iiAdd(const double& ii);

  /**
   * @brief get current v
   * @return current V
   */
  double getCurrentV() const;

  /**
   * @brief get initial voltage of the bus
   * @return initial voltage of the bus
   */
  inline double getU0() const {
    return u0_;
  }

  /**
   * @brief get initial angle of the bus
   * @return initial angle of the bus
   */
  inline double getAngle0() const {
    return angle0_;
  }

  std::vector<boost::weak_ptr<ModelBus> > neighbors_;  ///< list of buses within the same AC-connected component

  /**
   * @brief  scan a subnetwork in order to find all neighboring buses
   * @param subNetwork
   * @param numComponent
   */
  void exploreNeighbors(const int& numComponent, const boost::shared_ptr<SubNetwork>& subNetwork);  // scan a subnetwork to find all neighbouring buses

  /**
   * @brief set refislands
   * @param refIsland
   */
  inline void setRefIslands(int refIsland) {
    refIslands_ = refIsland;
  }

  /**
   * @brief get refislande
   * @return refisland
   */
  inline int getRefIslands() const {
    return refIslands_;
  }

  /**
   * @brief init derivatives
   */
  void initDerivatives();

  /**
   * @brief get derivatives
   * @return the derivatives associated to the bus model
   */
  inline boost::shared_ptr<BusDerivatives> derivatives() const {
    return derivatives_;
  }

  /**
   * @brief  switch off the bus (and force the voltage to be set to 0)
   */
  void switchOff();  // switch off the bus (and force the voltage to be set to 0)

  /**
   * @brief switch on the bus
   */
  inline void switchOn() {
    switchOff_ = false;
  }  // switch on the bus

  /**
   * @brief get information about whether the bus is switched off
   * @return @b tur if the bus is switched off, @b false otherwise
   */
  inline bool getSwitchOff() const {
    return switchOff_;
  }  // get information about whether the bus is switched off

  /**
   * @copydoc NetworkComponent::Impl::evalJt(SparseMatrix& jt, const double& cj, const int& rowOffset)
   */
  void evalJt(SparseMatrix& jt, const double& cj, const int& rowOffset);

  /**
   * @copydoc NetworkComponent::Impl::evalJtPrim(SparseMatrix& jt, const int& rowOffset)
   */
  void evalJtPrim(SparseMatrix& jt, const int& rowOffset);

  /**
   * @brief retrieve the real part of the voltage
   * @return the real part of the voltage
   */
  double ur() const;

  /**
   * @brief retrieve the imaginary part of the voltage
   * @return the imaginary part of the voltage
   */
  double ui() const;

  /**
   * @brief get urYNum
   * @return urYNum
   */
  inline int urYNum() const {
    return urYNum_;
  }

  /**
   * @brief get uiYNum
   * @return uiYNum
   */
  inline int uiYNum() const {
    return uiYNum_;
  }

  /**
   * @brief set the number of independent sub networks
   * @param num number of the sub network
   */
  inline void numSubNetwork(int num) {
    numSubNetwork_ = num;
  }  // set the number of independent sub networks

  /**
   * @brief check whether the sub-network index has already been set
   * @return @b whether the sub-network index has already been set
   */
  bool numSubNetworkSet() const;

  /**
   * @brief clear the sub-network index
   */
  inline void clearNumSubNetwork() {
    numSubNetwork_.reset();
  }

  /**
   * @brief get the number of independent sub networks
   * @return numSubNetwork_
   */
  inline int numSubNetwork() const {
    return numSubNetwork_.value();
  }  // get the number of independent sub networks

  /**
   * @brief get nominal voltage
   * @return norminal voltage
   */
  inline double getVNom() const {
    return unom_;
  }

  /**
   * @brief setter for the voltage level that contains the bus
   * @param voltageLevel VoltageLevel model that contains the bus
   */
  inline void setVoltageLevel(const boost::weak_ptr<ModelVoltageLevel>& voltageLevel) {
    modelVoltageLevel_ = voltageLevel;
  }

  /**
   * @brief getter for the voltage level that contains the bus
   * @return the voltage level that contains the bus
   */
  inline boost::shared_ptr<ModelVoltageLevel> getVoltageLevel() const {
    return modelVoltageLevel_.lock();
  }

  /**
   * @brief getter for the boolean indicating whether the bus has a bus bar section
   * @return whether the bus has a bus bar section
   */
  inline bool hasBBS() const {
    return !busBarSectionNames_.empty();
  }

  /**
   * @brief getter for the bus index
   * @return the bus index
   */
  inline int getBusIndex() const {
    return busIndex_;
  }

  /**
   * @brief add a model of switch to the list of connectable switches
   * @param sw model of switch to add
   */
  inline void addSwitch(const boost::weak_ptr<ModelSwitch>& sw) {
    connectableSwitches_.push_back(sw);
  }

 private:
  /**
   * @brief define elements of the bus model using id as prefix (to deal with alias)
   * @param id id to use as prefix
   * @param elements vector of elements to fill with new elements defined
   * @param mapElement map of elements to fill with new elements
   */
  void defineElementsById(const std::string& id, std::vector<Element> &elements, std::map<std::string, int>& mapElement);

 private:
  boost::weak_ptr<ModelVoltageLevel> modelVoltageLevel_;  ///< voltage level that contains the bus

  double uMin_;  ///< minimum allowed voltage
  double uMax_;  ///< maximum allowed voltage
  bool stateUmax_;  ///< whether U > Umax
  bool stateUmin_;  ///< whether U < Umin

  bool switchOff_;  ///< whether the bus was switched off
  // equivalent to switchOff_ but with discrete variable, to be able to switch off a node thanks to an outside event
  State connectionState_;  ///< connection status
  double irConnection_;  ///< real current injected
  double iiConnection_;  ///< imaginary current injected
  int refIslands_;  ///< island reference (used to compute switch loops)
  boost::shared_ptr<BusDerivatives> derivatives_;  ///< derivatives
  double ur0_;  ///< initial real voltage
  double ui0_;  ///< initial imaginary voltage
  double ir0_;  ///< residual real current
  double ii0_;  ///< residual imaginary current

  // index inside the whole Jacobian
  int urYNum_;  ///< index ur
  int uiYNum_;  ///< ui
  int iiYNum_;  ///< ii
  int irYNum_;  ///< ir

  int busIndex_;  ///< index of bus in its voltage level
  bool hasConnection_;  ///< whether has connection

  boost::optional<int> numSubNetwork_;  ///< number of subnetworks

  double unom_;  ///< nominal voltage
  double u0_;  ///< initial voltage
  double angle0_;  ///< initial angle
  std::vector<std::string> busBarSectionNames_;  ///< name of bus bar sections on the same electrical node
  std::vector<boost::weak_ptr<ModelSwitch> > connectableSwitches_;  ///< switch connected or connectable on the node
};

/**
 * class SubNetwork
 */
class SubNetwork {  ///< sub-network gathering buses connected by AC components
 public:
  /**
   * @brief default constructor
   */
  SubNetwork()
  :num_(0) { }

  /**
   * @brief destructor
   */
  ~SubNetwork() { }

  /**
   * @brief constructor
   * @param num
   */
  explicit SubNetwork(const int& num)
  :num_(num) { }

  /**
   * @brief set num
   * @param num
   */
  inline void setNum(int num) {
    num_ = num;
  }

  /**
   * @brief  add a bus to the sub-network
   * @param bus
   */
  inline void addBus(const boost::shared_ptr<ModelBus>& bus) {
    bus_.push_back(bus);
  }   // add a bus to the sub-network

  /**
   * @brief  get the number of buses within the sub-network
   * @return number of buses
   */
  inline unsigned int nbBus() const {
    return bus_.size();
  }   // get the number of buses within the sub-network

  /**
   * @brief get bus
   * @param num
   * @return bus
   */
  inline boost::shared_ptr<ModelBus> bus(int num) const {
    return bus_[num];
  }
  /**
   * @brief  switch off all buses within the sub-network
   *
   */
  void shutDownNodes();   // switch off all buses within the sub-network
  /**
   * @brief turn on all buses within the sub-network
   *
   */
  void turnOnNodes();  // turn on all buses within the sub-network

 private:
  int num_;  ///< number of bus
  std::vector<boost::shared_ptr<ModelBus> > bus_;  ///< vector of ModelBus located within the sub-network
};

/**
 * class ModelBusContainer
 */
class ModelBusContainer {
 public:
  /**
   * @brief default constructor
   */
  ModelBusContainer();

  /**
   * @brief destructor
   */
  ~ModelBusContainer() { }

  /**
   * @brief add bus
   * @param model
   */
  void add(const boost::shared_ptr<ModelBus>& model);

  /**
   * @brief remove all buses from the sub-network
   *
   */
  void resetSubNetwork();   // remove all buses from the sub-network

  /**
   * @brief  reset node injection
   *
   */
  void resetNodeInjections();

  /**
   * @brief create a new-subnetwork, and scan the network to find all buses located within
   *
   */
  void exploreNeighbors();  // create a new-subnetwork, and scan the network to find all buses located within

  /**
   * @brief init reference islands
   *
   */
  void initRefIslands();

  /**
   * @brief init derivatives
   *
   */
  void initDerivatives();

  /**
   * @brief evaluate the residual functions for each buses
   *
   */
  void evalF();

  /**
   * @brief get sub networks
   * @return sub networks
   */
  std::vector<boost::shared_ptr<SubNetwork> > getSubNetworks() const {
    return subNetworks_;
  }   // get the list of sub-networks

  /**
   * @brief evaluate Jacobian \f$( J = @F/@x + cj * @F/@x')\f$
   * @param jt sparse matrix to fill
   * @param cj Jacobian prime coefficient
   * @param rowOffset row offset to use to find the first row to fill
   */
  void evalJt(SparseMatrix& jt, const double& cj, const int& rowOffset);

  /**
   * @brief  evaluate Jacobian \f$( J =  @F/@x')\f$
   * @param jt sparse matrix to fill
   * @param rowOffset row offset to use to find the first row to fill
   */
  void evalJtPrim(SparseMatrix& jt, const int& rowOffset);

 private:
  std::vector<boost::shared_ptr<ModelBus> > models_;  ///< model bus
  std::vector<boost::shared_ptr<SubNetwork> > subNetworks_;  ///< sub network
};
}  // namespace DYN
#endif  // MODELS_CPP_MODELNETWORK_DYNMODELBUS_H_
