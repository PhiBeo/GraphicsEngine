#pragma once

#include "RenderObjectComponent.h"

namespace SumEngine
{
	class ModelComponent final : public RenderObjectComponent
	{
	public:
		SET_TYPE_ID(ComponentId::Model);

		void Initialize() override;
		void Terminate() override;

		void Deserialize(const rapidjson::Value& value) override;

		Graphics::ModelId GetModelId() const override;
		const Graphics::Model& GetModel() const override;

	private:
		std::string mFileName;
		Graphics::ModelId mModelId;

		using Animations = std::vector<std::string>;
		Animations mAnimations;
	};
}