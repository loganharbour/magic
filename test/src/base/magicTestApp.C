//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "magicTestApp.h"
#include "magicApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
magicTestApp::validParams()
{
  InputParameters params = magicApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

magicTestApp::magicTestApp(InputParameters parameters) : MooseApp(parameters)
{
  magicTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

magicTestApp::~magicTestApp() {}

void
magicTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  magicApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"magicTestApp"});
    Registry::registerActionsTo(af, {"magicTestApp"});
  }
}

void
magicTestApp::registerApps()
{
  registerApp(magicApp);
  registerApp(magicTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
magicTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  magicTestApp::registerAll(f, af, s);
}
extern "C" void
magicTestApp__registerApps()
{
  magicTestApp::registerApps();
}
