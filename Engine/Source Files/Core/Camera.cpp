#include "../Headers/Entities/Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float left, float right, float bottom, float top) :
	m_projectionMatrix(glm::ortho(left, right, bottom, top, -1.f, 1.f)), m_viewMatrix(1.f)
{
	m_ViewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}

//glm::vec3& Camera::SetCameraTarget(float x, float y)
//{
//	// TODO: insert return statement here
//}

//glm::vec3& Camera::UpdateCameraPosition(float x, float y)
//{
//	// TODO: insert return statement here
//}

void Camera::SetProjection(float left, float right, float bottom, float top)
{
	m_projectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
	m_ViewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}

void Camera::Update(float x, float y)
{
	cameraPosition.x = x;
	cameraPosition.y = y;
}

void Camera::RecalculateViewMatrix()
{
	glm::mat4 transform = glm::translate(glm::mat4(1.0f), cameraPosition) * glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation), glm::vec3(0, 0, 1));

	m_viewMatrix = glm::inverse(transform);
	m_ViewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}