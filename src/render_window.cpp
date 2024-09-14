/**
  ******************************************************************************
  * @file           : render_window.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/9/13
  ******************************************************************************
  */

#include <glad/glad.h>

#include <imgui/backends/imgui_impl_opengl3.h>
#include <imgui/backends/imgui_impl_glfw.h>

#include <iostream>

#include "render_window.hpp"

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

RenderWindow::RenderWindow(int wndSizeX, int wndSizeY)
 : m_wndSizeX(wndSizeX), m_wndSizeY(wndSizeY) {
    m_wnd = nullptr;
    m_clearColor = ImVec4(0.f, 0.f, 0.f, 1.f);
}

RenderWindow::~RenderWindow() {
    close();
}

bool RenderWindow::init() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return false;

    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only

#if defined(__APPLE__)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#endif

    m_wnd = glfwCreateWindow(m_wndSizeX, m_wndSizeY, "RayTracing RenderWindow", nullptr, nullptr);
    if (m_wnd == nullptr)
        return false;
    glfwMakeContextCurrent(m_wnd);
    glfwSwapInterval(1); // Enable vsync

    // GLAD加载系统相关的OpenGL函数指针地址
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // GLAD加载失败报错
        std::cout << "ERROR::GLAD::INITIALIZATION_FAILED" << std::endl;
    }

    // set up ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    // setup imGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_wnd, true);
#ifdef __EMSCRIPTEN__
    ImGui_ImplGlfw_InstallEmscriptenCallbacks(window, "#canvas");
#endif
    ImGui_ImplOpenGL3_Init(glsl_version);

    return true;
}

void RenderWindow::close() {
    if(!m_wnd) {
        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(m_wnd);
        m_wnd = nullptr;

        glfwTerminate();
    }
}

bool RenderWindow::isWndShouldClose() {
    return glfwWindowShouldClose(m_wnd);
}

bool RenderWindow::BeginWindow() {
    // 当窗口未初始化并且尝试初始化不成功时返回false
    if(m_wnd == nullptr && !init()) {
        return false;
    }

    // 如果窗口被关闭，返回false
    if(isWndShouldClose()) {
        return false;
    }

    // 未被关闭的话则进入主循环

    // Main loop
#ifdef __EMSCRIPTEN__
    // For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini file.
    // You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
//    while (!glfwWindowShouldClose(_wnd))
#endif

    // Poll and handle events (inputs, window resize, etc.)
    // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
    // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
    // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
    // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
    glfwPollEvents();
    if (glfwGetWindowAttrib(m_wnd, GLFW_ICONIFIED) != 0)
    {
        return false;
    }

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    return true;
}

void RenderWindow::EndWindow() {

    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(m_wnd, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(m_clearColor.x * m_clearColor.w, m_clearColor.y * m_clearColor.w, m_clearColor.z * m_clearColor.w, m_clearColor.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(m_wnd);

#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif
}
