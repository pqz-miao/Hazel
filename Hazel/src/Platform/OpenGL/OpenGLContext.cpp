#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Hazel {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		HZ_CORE_INFO("OpenGL Info:");
		const auto vendor = glGetString(GL_VENDOR);
		const auto renderer = glGetString(GL_RENDERER);
		const auto version = glGetString(GL_VERSION);
		HZ_CORE_INFO("Vendor: {0}", vendor ? reinterpret_cast<const char*>(vendor) : "Unknown");
		HZ_CORE_INFO("Renderer: {0}", renderer ? reinterpret_cast<const char*>(renderer) : "Unknown");
		HZ_CORE_INFO("Version: {0}", version ? reinterpret_cast<const char*>(version) : "Unknown");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
