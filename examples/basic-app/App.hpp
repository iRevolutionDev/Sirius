#include "Application.h"

class BasicApp : public Sirius::Application
{
public:
	void OnRender() override
	{
		ImGui::ShowDemoWindow();
	};
};