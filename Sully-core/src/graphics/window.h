#pragma once
#include <GLFW/glfw3.h>

namespace sully { namespace graphics {
	//Resize window
	void windowResize(GLFWwindow *window, int width, int height);

	class Window {
	private:
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;
	public:
		Window(const char *p_name, int p_width, int p_height);
		~Window();
		void clear() const;
		bool closed() const;
		void update();

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
	private:
		bool init();
	};
} }