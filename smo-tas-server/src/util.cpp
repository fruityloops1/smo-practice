#include <util.h>

    smo::Quatf fl::eulerToQuat(smo::Vector3f euler) {

        smo::Quatf quat;

        f32 cy = cos(euler.y / 2);
        f32 sy = sin(euler.y / 2);
        f32 cp = cos(euler.z / 2);
        f32 sp = sin(euler.z / 2);
        f32 cr = cos(euler.x / 2);
        f32 sr = sin(euler.x / 2);

        quat.w = cr * cp * cy + sr * sp * sy;
        quat.x = sr * cp * cy - cr * sp * sy;
        quat.z = cr * sp * cy + sr * cp * sy;
        quat.y = cr * cp * sy - sr * sp * cy;

        return quat;
    }