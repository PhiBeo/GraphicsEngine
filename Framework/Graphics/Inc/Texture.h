#pragma once

namespace SumEngine::Graphics
{
    class Texture
    {
    public:
        static void UnbindPS(uint32_t slot);

        enum class Format
        {
            RGBA_U8,
            RGBA_U32
        };

        Texture() = default;
        virtual ~Texture();

        // delete copy
        Texture(const Texture&) = delete;
        Texture& operator=(const Texture&) = delete;

        // allow move
        Texture(Texture&& rhs) noexcept;
        Texture& operator=(Texture&& rhs) noexcept;

        virtual void Initialize(const std::filesystem::path& fileName);
        virtual void Initialize(uint32_t width, uint32_t height, Format format);
        virtual void Terminate();

        void BindVS(uint32_t slot) const;
        void BindPS(uint32_t slot) const;

        void* GetRawData() const;

        uint32_t GetWidth() const;
        uint32_t GetHeight() const;

    protected:
        ID3D11ShaderResourceView* mShaderResourceView = nullptr;

        DXGI_FORMAT GetDXGIFormat(Format format);

        uint32_t mWidth = 0;
        uint32_t mHeight = 0;
    };
}