#include "Precompiled.h"
#include "UISprite.h"

using namespace SumEngine;
using namespace SumEngine::Graphics;

UISprite::~UISprite()
{
}

void UISprite::Initialize(const std::filesystem::path& filePath)
{
	TextureCache* tc = TextureCache::Get();
	mTextureId = tc->LoadTexture(filePath);
	const Texture* texture = tc->GetTexture(mTextureId);
	ASSERT(texture != nullptr, "UISprite: texture [%s] was not found", filePath.u8string().c_str());
	SetRect(0, 0, texture->GetWidth(), texture->GetHeight());
}

void UISprite::Terminate()
{
}

void UISprite::SetPosition(const Math::Vector2& position)
{
	mPosition.x = position.x;
	mPosition.y = position.y;
}

void UISprite::SetScale(const Math::Vector2& scale)
{
	mScale.x = scale.x;
	mScale.y = scale.y;
}

void UISprite::SetRect(const uint32_t top, uint32_t left, uint32_t right, uint32_t bottom)
{
	mRect.top = top;
	mRect.left = left;
	mRect.right = right;
	mRect.bottom = bottom;
	UpdateOrigin();
}

void UISprite::SetPivot(Pivot pivot)
{
	mPivot = pivot;
	UpdateOrigin();
}

void UISprite::SetFlip(Flip flip)
{
	switch (flip)
	{
	case SumEngine::Graphics::Flip::None:
		mFlip = DirectX::SpriteEffects_None;
		break;
	case SumEngine::Graphics::Flip::Horizontal:
		mFlip = DirectX::SpriteEffects_FlipHorizontally;
		break;
	case SumEngine::Graphics::Flip::Vertical:
		mFlip = DirectX::SpriteEffects_FlipVertically;
		break;
	case SumEngine::Graphics::Flip::Both:
		mFlip = DirectX::SpriteEffects_FlipBoth;
		break;
	default:
		break;
	}
}

void UISprite::SetColor(const Color& color)
{
	mColor.m128_f32[0] = color.r;
	mColor.m128_f32[1] = color.g;
	mColor.m128_f32[2] = color.b;
	mColor.m128_f32[3] = color.a;
}

void UISprite::SetRotation(float rotation)
{
	mRotation = rotation;
}

bool UISprite::IsInSprite(float x, float y) const
{
	const float width = mRect.right - mRect.left;
	const float height = mRect.bottom - mRect.top;
	return x >= mPosition.x - mOrigin.x && x <= mPosition.x + width - mOrigin.x &&
		 y >= mPosition.y - mOrigin.y && y <= mPosition.y + height - mOrigin.y;
}

void UISprite::GetOrigin(float& x, float& y)
{
	x = mOrigin.x;
	y = mOrigin.y;
}

constexpr DirectX::XMFLOAT2 gOffsets[] =
{
	{0.0f, 0.0f},	//topleft
	{0.5f, 0.0f},	//top
	{1.0f, 0.0f},	//topright
	{0.0f, 0.5f},	//left
	{0.5f, 0.5f},	//center
	{1.0f, 0.5f},	//right
	{0.0f, 1.0f},	//bottomleft
	{0.5f, 1.0f},	//bottom
	{1.0f, 1.0f}	//bottomright
};

void UISprite::UpdateOrigin()
{
	const float width = mRect.right - mRect.left;
	const float height = mRect.bottom - mRect.top;
	auto index = static_cast<std::underlying_type_t<Pivot>>(mPivot);
	mOrigin = { width * gOffsets[index].x, height * gOffsets[index].y };
}
