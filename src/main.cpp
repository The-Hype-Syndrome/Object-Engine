#include"object-engine.h"


int main() {
	using namespace object;
	using namespace graphics;

	WindowOBJ window("New OBJ Window", 960, 680);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	float x, y;
	x = 0.2;
	y = 0.2;
	double d, e;
	while (!window.is_closed())
	{
		window.clear();
		if (window.getKeyInput(GLFW_KEY_A)) {
			x += 0.001;
			y += 0.001;
		}
		else {
			x -= 0.001;
			y -= 0.001;
		}
		if (window.getMouseInput(mouse1))
		{
			x = 0.5;
			y = 0.5;
		}
		window.getMousePos(d, e);
		std::cout << d << ',' << e << std::endl;
		glBegin(GL_QUADS);
		glVertex2f(-x, -y);
		glVertex2f(-x, y);
		glVertex2f(x, y);
		glVertex2f(x, -y);
		glEnd();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
		window.update();
	}

	return 0;
}