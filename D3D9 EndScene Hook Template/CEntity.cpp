#include "stdafx.h"
#include "CEntity.hpp"
#include "Offsets.hpp"

CEntity::CEntity()
{
}

CEntity::~CEntity()
{
}

void CEntity::setId(int i)
{
	m_iId = i;
}

int CEntity::getId()
{
	return m_iId;
}

DWORD* CEntity::getEntityBase()
{
	return (DWORD*)(gOffsets->dwEntityList + ( m_iId * 0x10));
}

Vector* CEntity::getPosition()
{
	return (Vector*)(getEntityBase() + gOffsets->m_vecOrigin);
}

Vector CEntity::getBonePosition(int bone)
{
	DWORD boneMatrix = (DWORD)(getEntityBase() + gOffsets->m_dwBoneMatrix);
	Vector dst;
	dst.x = *(float*)(boneMatrix + 0x30 * bone + 0x0C);
	dst.y = *(float*)(boneMatrix + 0x30 * bone + 0x1C);
	dst.z = *(float*)(boneMatrix + 0x30 * bone + 0x2C);
	return dst;
}

int CEntity::getHealth()
{
	return (int)(getEntityBase() + gOffsets->m_iHealth);
}

int CEntity::getTeam()
{
	return (int)(getEntityBase() + gOffsets->m_iTeamNum);
}

bool CEntity::isAlive()
{
	return getHealth() > 0 ? true : false;
}
