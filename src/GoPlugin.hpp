#pragma once
#include "main.hpp"
#include "golang_defines.hpp"
#include "golang_api.hpp"

class GoPlugin 
{
	public:
		GoPlugin();

		static GoPlugin& GetInstance() { static GoPlugin instance; return instance; }
		rage::IMultiplayer *GetMultiplayer() { return m_mp; }

		void Initialize();
		bool InitPackage(const std::string& path);
		void Terminate();
		void SetMultiplayer(rage::IMultiplayer *mp);

	private:
		rage::IMultiplayer *m_mp;
};

namespace RAGEMP
{
	class EventHandler : public rage::IEventHandler, public rage::IPlayerHandler, public rage::ITickHandler
	{
		public:
			static EventHandler& GetInstance() { static EventHandler instance; return instance; }
			virtual ITickHandler *GetTickHandler() { return this; }
			virtual void Tick() {  }
	};
}