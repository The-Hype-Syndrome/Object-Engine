#include "obj-window.h"

namespace object {
	namespace graphics {

		bool WindowOBJ::w_keys[MAX_KEYS];
		bool WindowOBJ::w_mouseButtons[MAX_M_BUTTONS];
		double WindowOBJ::mx;
		double WindowOBJ::my;

		void window_resize(GLFWwindow* window, int wd, int ht);
		void obj_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void obj_mouse_callback(GLFWwindow* window, int button, int action, int mods);
		void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);


		WindowOBJ::WindowOBJ(const char* title, int wd, int ht) {
			w_title = title;
			w_width = wd;
			w_height = ht;

			if (!objInit()) {
				glfwTerminate();
			}
			for (int i = 0; i < MAX_KEYS; i++)
			{
				w_keys[i] = false;
			}
			for (int i = 0; i < MAX_M_BUTTONS; i++)
			{
				w_mouseButtons[i] = false;
			}
		}

		WindowOBJ::~WindowOBJ() {
			glfwTerminate();
		}

		void WindowOBJ::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool WindowOBJ::getKeyInput(unsigned int in_key) {
			if (in_key >= MAX_KEYS)
				return false;
			return w_keys[in_key];
		}

		bool WindowOBJ::getMouseInput(unsigned int in_m) {
			if (in_m >= MAX_M_BUTTONS)
				return false;
			return w_mouseButtons[in_m];
		}
		void WindowOBJ::getMousePos(double &x,double &y) {
			x = mx;
			y = my;
		}

		void WindowOBJ::update() {
			glfwSwapBuffers(w_window);
			glfwPollEvents();
		}

		bool WindowOBJ::is_closed() const {
			return glfwWindowShouldClose(w_window);
		}

		bool WindowOBJ::objInit() {

			if (!glfwInit()) {
				std::cout << "Error. Initialization wasn't successful :(";
				return false;
			}

			w_window = glfwCreateWindow(w_width, w_height, w_title, NULL, NULL);
			if (!w_window)
			{
				glfwTerminate();
				std::cout << "Window creation failed\n";
				return false;
			}
			glfwMakeContextCurrent(w_window);
			glfwSetWindowUserPointer(w_window, this);
			glfwSetWindowSizeCallback(w_window, window_resize);
			glfwSetMouseButtonCallback(w_window, obj_mouse_callback);
			glfwSetCursorPosCallback(w_window, mouse_pos_callback);
			glfwSetKeyCallback(w_window, obj_key_callback);


			if (glewInit() != GLEW_OK) {
				std::cout << "GLEW intialization failed :[\n";
				return false;
			}
			std::cout << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		void window_resize(GLFWwindow* window, int wd, int ht) {
			glViewport(0, 0, wd, ht);
		}

		void obj_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowOBJ* win = (WindowOBJ*)glfwGetWindowUserPointer(window);
			win->w_keys[key] = action != GLFW_RELEASE;;
		}

		void obj_mouse_callback(GLFWwindow* window, int button, int action, int mods) {
			WindowOBJ* win = (WindowOBJ*)glfwGetWindowUserPointer(window);
			win->w_mouseButtons[button] = action != GLFW_RELEASE;
		}

		void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos) {
			WindowOBJ* win = (WindowOBJ*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}

	}
}