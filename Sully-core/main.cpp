#include <iostream>
#include <GLFW/glfw3.h>
#include "src/graphics/window.h"

int main() {
	using namespace sully;
	using namespace graphics;

	//Create a game Window.
	Window window("Sully!", 800, 600);
	//Clear the window with a nice blue
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
    //Print the version
	std::cout << glGetString(GL_VERSION) << std::endl;
	//While window is up
	while (!window.closed())
	{
	    //Print the dimensions
		std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		//Clear the window
		window.clear();
		//Draw a triangle
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		//Update the window
		window.update();
	}

	system("PAUSE");
	return 0;
}