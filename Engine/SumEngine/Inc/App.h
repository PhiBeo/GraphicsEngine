#pragma once

namespace SumEngine
{
    class AppState;

    struct AppConfig
    {
        std::wstring appName = L"AppName";
        uint32_t winWidth = 1280;
        uint32_t winHeight = 720;
        uint32_t maxDrawLines = 100000;
    };

    class App final
    {
    public:
        void Run(const AppConfig& config);
        void Quit();

        template<class StateType>
        void AddState(const std::string& stateName)
        {
            static_assert(std::is_base_of_v<AppState, StateType>,
                "App: State must be of type AppState");

            auto [iter, success] = mAppStates.try_emplace(stateName, nullptr);
            if (success)
            {
                auto& ptr = iter->second;
                ptr = std::make_unique<StateType>();
                if (mCurrentState == nullptr)
                {
                    LOG("App: Current state %s", stateName.c_str());
                    mCurrentState = ptr.get();
                }
            }
        }

        void ChangeState(const std::string& stateName);

    private:
        using AppStateMap = std::map<std::string, std::unique_ptr<AppState>>;

        AppStateMap mAppStates;
        AppState* mCurrentState = nullptr;
        AppState* mNextState = nullptr;
        bool mRunning = false;
    };
}