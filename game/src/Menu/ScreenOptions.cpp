#include "ScreenOptions.h"
#include "raylib.h"


ScreenOptionsState::ScreenOptionsState()
{

}

ScreenOptionsState& ScreenOptionsState::getInstance()
{
	static ScreenOptionsState singleton;
	return singleton;
}

void ScreenOptionsState::InitScreen(void)
{
	framesCounter = 0;
	finishScreen = 0;
}

void ScreenOptionsState::UpdateScreen(float deltaTime)
{
	if (IsKeyPressed(KEY_O))
	{
		finishScreen = 1;   // TITLE
	}
}

void ScreenOptionsState::DrawScreen(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

    const char* line1 = "To move KEN use the direction keys, you can also jump and crouch";
    const char* line2 = "To punch, you can press Q for light punch or W for medium punch";
    const char* line3 = "To win, KEN has to destroy the car";
    const char* line4 = "You lose if the TIME reach 0.";
    const char* line5 = "You can access debug mode pressing D";
    

    DrawText(line1, (GetScreenWidth() / 2) - (MeasureText(line1, 20) / 2.), 150, 20, WHITE);
    DrawText(line2, (GetScreenWidth() / 2) - (MeasureText(line2, 20) / 2.), 180, 20, WHITE);
    DrawText(line3, (GetScreenWidth() / 2) - (MeasureText(line3, 20) / 2.), 210, 20, WHITE);
    DrawText(line4, (GetScreenWidth() / 2) - (MeasureText(line4, 20) / 2.), 240, 20, WHITE);
    DrawText(line5, (GetScreenWidth() / 2) - (MeasureText(line5, 20) / 2.), 270, 20, WHITE);

    const char* line6 = "Press 'O' to return to Title.";

    DrawText(line6, (GetScreenWidth() / 2.f) - (MeasureText(line6, 20) / 2.), 380, 20, WHITE);

}

void ScreenOptionsState::UnloadScreen(void)
{

}

int ScreenOptionsState::FinishScreen(void)
{
	return finishScreen;
}