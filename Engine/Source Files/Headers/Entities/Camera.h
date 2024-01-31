#pragma once
#include <../include/glm/glm.hpp>
#include <../include/glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	inline static Camera* GetInstance() { return (s_instance != nullptr) ? s_instance : new Camera(glm::mat4 {0.0f}); }

	virtual ~Camera();

	const glm::mat4& GetProjectionMatrix() const { return m_projectionMatrix; }
	const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
	
	const glm::mat4& GetViewMatrix() const { return m_viewMatrix; }
	const glm::vec3& GetPosition() const { return cameraPosition; }
	float GetRotation() const { return m_rotation; }
	const glm::vec3& GetCameraTarget() const { return cameraTarget; }

	glm::vec3& SetCameraTarget(float x, float y);
	glm::vec3& UpdateCameraPosition(float x, float y);

	void SetProjection(float left, float right, float bottom, float top);
	void SetPosition(const glm::vec3 position) { cameraPosition = position; RecalculateViewMatrix(); }
	void SetRotation(float rotation) { m_rotation = rotation; RecalculateViewMatrix(); }

	void Update(float x, float y);

private:

	static Camera* s_instance;
	Camera(float left, float right, float bottom, float top);
	Camera(const glm::mat4 projection) : m_projectionMatrix(projection) {}
	
	glm::mat4 m_projectionMatrix {};
	glm::mat4 m_viewMatrix {};
	glm::mat4 m_ViewProjectionMatrix {};
	float m_left {}; float m_right {}; float m_top {}; float m_bottom {};



	glm::vec3 cameraPosition = {cameraX, cameraY, 1.f};
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDirection = glm::normalize(cameraPosition - cameraTarget);

	const glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRightAxis = glm::normalize(glm::cross(upVector, cameraDirection));
	glm::vec3 cameraUpAxis = glm::cross(cameraDirection, cameraRightAxis);


	glm::mat4 view = glm::lookAt(cameraPosition, cameraTarget, upVector);

	float cameraX = 0.f; float cameraY = 0.f;
	//this might be useful
	float m_rotation = 0.0f;


	//3d camera stuff
	glm::vec3 direction;
	float yaw{};
	float pitch{};
	float fov{};




private:
	void RecalculateViewMatrix();



	
};


