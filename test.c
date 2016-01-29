#include <GLFW/glfw3.h>
#include "libft.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		ft_putstr("bye");
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void display(double x, double y) {

	if (x >= 0 && x <= 620)
	{
		x= 2 * (x - 320)/640;
		y= 2 * (240 - y)/480;

		glClearColor(1.0f,1.0f, 1.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3f(0.0f, 0.0f, 0.0f);
		glRectf(x, -0.75f, x + 0.1, -0.8f);
	}
}

int main(void)
{
	GLFWwindow* window;
	double xpos, ypos;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glfwGetCursorPos(window, &xpos, &ypos);

		glfwSetKeyCallback(window,key_callback);

		display(xpos, ypos);

		ft_putstr("x:");
		ft_putnbr((int)xpos);
		ft_putstr("y:");
		ft_putnbr((int)ypos);
		ft_putstr("\n");
		ft_putstr("\n");

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
