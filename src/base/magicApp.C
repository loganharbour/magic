#include "magicApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
magicApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

magicApp::magicApp(InputParameters parameters) : MooseApp(parameters)
{
  magicApp::registerAll(_factory, _action_factory, _syntax);
}

magicApp::~magicApp() {}

void
magicApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<magicApp>(f, af, s);
  Registry::registerObjectsTo(f, {"magicApp"});
  Registry::registerActionsTo(af, {"magicApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
magicApp::registerApps()
{
  registerApp(magicApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
magicApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  magicApp::registerAll(f, af, s);
}
extern "C" void
magicApp__registerApps()
{
  magicApp::registerApps();
}
