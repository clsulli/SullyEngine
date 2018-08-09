#include "window.h"
#include <iostream>

namespace sully {
    namespace graphics {
        //Construct Window with a title, width and height.
        Window::Window(const char *p_Title, int p_Width, int p_Height) {
            this->m_Title = p_Title;
            this->m_Width = p_Width;
            this->m_Height = p_Height;
            if (!sully::graphics::Window::init()) {
                glfwTerminate();
            }
        }

        //Deconstruct window by termination.
        Window::~Window() {
            glfwTerminate();
        }


        bool Window::init() {
            /* This function tries to initialize GLFW and create the window that can be drawn too.  If anything fails, it alerts
             * the user on what failed.
             */

            //  Try to initialize GLFW
            if (!glfwInit()) {
                // If it fails to initialize, alert user.
                std::cout << "Failed to initialize GLFW" << std::endl;
                return false;
            }
            // Create the window that can be drawn to.  m_Window is set to NULL if the window creation fails.
            m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
            if (!m_Window) {
                // If window creation fails, alert user.
                std::cout << "Failed to create GLFW window!" << std::endl;
                return false;
            }
            // Sets the specified window to the current glfw context.
            glfwMakeContextCurrent(m_Window);
            // Sets the size callback of the window passed in.
            glfwSetWindowSizeCallback(m_Window, windowResize);
            return true;
        }


        void Window::clear() const {
            //Clears the current screen
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }


        void Window::update() {
            //Process all events in the queue
            glfwPollEvents();
            //Gets the frame buffer size
            glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
            //Swaps the front and back buffers
            glfwSwapBuffers(m_Window);
        }


        bool Window::closed() const {
            //Returns if the window should close or not.
            return glfwWindowShouldClose(m_Window) == 1;
        }


        void windowResize(GLFWwindow *p_window, int width, int height) {
            //Resize the window
            glViewport(0, 0, width, height);
        }
    }
}