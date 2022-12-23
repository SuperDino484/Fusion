#pragma once

#include "fnpch.h"

namespace Fusion
{

	class Layer
	{
	public:
		explicit Layer(const std::string& Name, bool Enabled = true);
		virtual ~Layer();

		const std::string& GetName() const { return m_Name; }

		/**
		 * \brief Called when the application propagates the event to the layers
		 * \param Event The event which was triggered
		 */
		virtual void OnEvent(class Event& Event);

		/**
		 * \brief Called before start
		 */
		virtual void OnAwake();
		/**
		 * \brief Called before the application enters it main loop
		 */
		virtual void OnStart();
		/**
		 * \brief Called once per frame
		 */
		virtual void OnUpdate(float DeltaTime);
		/**
		 * \brief Called after the application loop ends
		 */
		virtual void OnEnd();
		/**
		 * \brief Called on the shutdown. Should not be preferred over OnEnd unless needed
		 */
		virtual void OnShutdown();

	private:
		/**
		 * \brief The name of the layer. Mostly for debug purposes
		 */
		std::string m_Name;
		/**
		 * \brief If the layer should be enabled
		 */
		bool m_Enabled;
	};

}

