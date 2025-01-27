#include "TexturesManager.h"

TextureManager::TextureManager()
{

}


void TextureManager::InitTexturesFiles()
{
    // Menu
    textLogo = LoadTexture("resources/Menu/Title.png");

    // Wallpaper
    wallpaper = LoadTexture("resources/Game/Stages/Ken-SF2-Stage_1920x1080.png");

    // Numbers
    numbers = LoadTexture("resources/UI/UI_MiscBig.png");

    // Ken Bonus
    kenBonus = LoadTexture("resources/Menu/KenBonusCar.png");

}

Texture2D& TextureManager::GetTexture(TextureType texturetype)
{
    switch (texturetype)
    {
    case TextureType::Logo:
        return textLogo;
        break;

    case TextureType::Wallpaper:
        return wallpaper;
        break;

    case TextureType::KenBonus:
        return kenBonus;
        break;
    }
}




void TextureManager::DrawNumber(int n, Vector2 position)
{
    if (n >= 0 && n < 10) {
        float m = 350 + n * 64;
        DrawTextureOriginRec(numbers, {m, 669, 62, 81 }, position, RAYWHITE,Vector2{0, 0});
    }
}

void TextureManager::DrawTextureOriginRec(Texture2D texture, Rectangle source, Vector2 position, Color tint, Vector2 newOrigin = Vector2{0, 0})
{
    Rectangle dest = { position.x, position.y, fabsf(source.width), fabsf(source.height) };

    Vector2 origin = newOrigin;

    DrawTexturePro(texture, source, dest, origin, 0.0f, tint);
}

void TextureManager::DrawTextureExCustom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)
{
    Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    Rectangle dest = { position.x, position.y, (float)texture.width * scale, (float)texture.height * scale };
    Vector2 origin = { (float)texture.width / 2.f, (float)texture.height / 2.f };

    DrawTexturePro(texture, source, dest, origin, rotation, tint);
}

void TextureManager::DrawTextureExCustomFromBottom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)
{
    Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    Rectangle dest = { position.x, position.y, (float)texture.width * scale, (float)texture.height * scale };
    Vector2 origin = { (float)texture.width / 2.f, (float)texture.height };

    DrawTexturePro(texture, source, dest, origin, rotation, tint);
}


void TextureManager::DrawTextureRecCustom(Texture2D texture, Rectangle Rectangle, Vector2 position, Color tint)
{
    Vector2 origin = { position.x - (Rectangle.width/2.f) , position.y - (Rectangle.height / 2.f) };
    DrawTextureRec(texture, Rectangle, origin, tint);
}

void TextureManager::UnloadTexturesFiles()
{
    UnloadTexture(textLogo);
    UnloadTexture(wallpaper);
    UnloadTexture(numbers);
    UnloadTexture(kenBonus);
}

