#pragma once
#include <vector>
#include <memory>
#include <string>
#include <functional>

#include "imgui.h"

namespace Sirius 
{
	class Application
	{
	public:
		Application();
		virtual ~Application();
		
		virtual void OnKeyEvent([[maybe_unused]] int Key, [[maybe_unused]] int scanCode, [[maybe_unused]] int Action, [[maybe_unused]] int Mods) {};
		virtual void OnRender() {};
	
	};
}