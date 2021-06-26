#pragma once

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

#define MAX_KEYS 1024
#define MAX_M_BUTTONS 32

namespace object {
	namespace graphics {

		class WindowOBJ {
		private:
			int w_width, w_height;
			const char* w_title;
			GLFWwindow* w_window;
			bool w_closed;

			static bool w_keys[MAX_KEYS];
			static bool w_mouseButtons[MAX_M_BUTTONS];
			static double mx, my;
		public:
			WindowOBJ(const char* title, int wd, int ht);
			~WindowOBJ();
			bool is_closed() const;
			void update();
			void clear() const;

			static bool getKeyInput(unsigned int in_key);
			static bool getMouseInput(unsigned int in_m);
			static void getMousePos(double& x, double& y);

		private:
			bool objInit();
			friend static void obj_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void obj_mouse_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
		};
}}
