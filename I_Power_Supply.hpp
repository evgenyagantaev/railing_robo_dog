#pragma once

class I_Power_Supply
{

	bool power_on_brain() = 0;
	bool power_on_locomotion() = 0;
	bool power_off_brain() = 0;
	bool power_off_locomotion() = 0;

}
