#pragma once

#include "raylib.h"
#include "Game/Characters/Character.h"


enum class TextureType
{
	Logo = 0,
	Wallpaper,
	KenBonus
};

class TextureManager
{
public:
	TextureManager();

	void InitTexturesFiles();
	void UnloadTexturesFiles();

	//Functons For textures
	Texture2D& GetTexture(TextureType texture);
	
	void DrawNumber(int n, Vector2 position);
	void DrawTextureOriginRec(Texture2D texture, Rectangle source, Vector2 position, Color tint, Vector2 newOrigin);
	void DrawTextureExCustom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
	void DrawTextureExCustomFromBottom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
	void DrawTextureRecCustom(Texture2D texture, Rectangle Rectangle, Vector2 position, Color tint);

private:
	Texture2D textLogo;
	Texture2D wallpaper;
	Texture2D numbers;
	Texture2D kenBonus;

};