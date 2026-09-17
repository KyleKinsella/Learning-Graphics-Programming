#ifndef QUAD_H
#define QUAD_H

#include "../book1/hittable.h"

class quad : public hittable {
public:
	quad(const point3& q, const vec3& u, const vec3& v, shared_ptr<material> mat) : q(q), u(u), v(v), mat(mat) {
		auto n = cross(u, v);
		normal = unit_vector(n);
		d = dot(normal, q);
		w = n / dot(n, n);
		
		set_bounding_box();
	}
	
	virtual void set_bounding_box() {
		// compute the bounding box of all four vertices
		auto bbox_diagonal1 = aabb(q, q + u + v);
		auto bbox_diagonal2 = aabb(q + u, q + q + v);
		bbox = aabb(bbox_diagonal1, bbox_diagonal2);
	}
	
	aabb bounding_box() const override { return bbox; }
	
	bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
		//~ return false; // TODO: program me!
		
		auto denom = dot(normal, r.direction());
		
		// no hit if the ray is parallel to the plane
		if (std::fabs(denom) < 1e-8)
			return false;
			
		// return false if the git point paramter 't' is outside the ray interval
		auto t = (d - dot(normal, r.origin())) / denom;
		if (!ray_t.contains(t))
			return false;
			
		// determine if the hit point lies within the planar shape using its plane coordinates	
		auto intersection = r.at(t);
		vec3 planar_hitpt_vector = intersection - q;
		auto alpha = dot(w, cross(planar_hitpt_vector, v));
		auto beta = dot(w, cross(u, planar_hitpt_vector));
		
		if (!is_interior(alpha, beta, rec))
			return false;
		
		// ray hits the 2d shape; set the rest of the hit record and return true
		rec.t = t;
		rec.p = intersection;
		rec.mat = mat;
		rec.set_face_normal(r, normal);
		
		return true;
	}
	
	virtual bool is_interior(double a, double b, hit_record& rec) const {
		interval unit_interval = interval(0, 1);
		// given the hit point, in plane coordinates, return false, if it is outside the primitive otherwise, set the hit record 'UV' coordinates and return true
		
		if (!unit_interval.contains(a) || !unit_interval.contains(b))
			return false;
			
		rec.u = a;
		rec.v = b;
		return true;
	}
	
private:
	point3 q;
	vec3 u, v;
	vec3 w;
	shared_ptr<material> mat;
	aabb bbox;
	vec3 normal;
	double d;
};

inline shared_ptr<hittable_list> box(const point3& a, const point3& b, shared_ptr<material> mat) {
	// returns the 3d box (six sides) that contain the two opposite vertices a & b
	auto sides = make_shared<hittable_list>();
	
	// construct the two opposite vertices with the minimum and maximum coordinates
	auto min = point3(std::fmin(a.x(), b.x()), std::fmin(a.y(), b.y()), std::fmin(a.z(), b.z()));
	auto max = point3(std::fmax(a.x(), b.x()), std::fmax(a.y(), b.y()), std::fmax(a.z(), b.z()));
	
	auto dx = vec3(max.x() - min.x(), 0, 0);
	auto dy = vec3(0, max.y() - min.y(), 0);
	auto dz = vec3(0, 0, max.z() - min.z());
	
	sides->add(make_shared<quad>(point3(min.x(), min.y(), max.z()), dx, dy, mat)); // front
	sides->add(make_shared<quad>(point3(max.x(), min.y(), max.z()), -dz, dy, mat)); // right
	sides->add(make_shared<quad>(point3(max.x(), min.y(), min.z()), -dx, dy, mat)); // back
	sides->add(make_shared<quad>(point3(min.x(), min.y(), min.z()), dz, dy, mat)); // left
	sides->add(make_shared<quad>(point3(min.x(), max.y(), max.z()), dx, -dz, mat)); // top
	sides->add(make_shared<quad>(point3(min.x(), min.y(), max.z()), dx, dz, mat)); // bottom
	
	return sides;
}

#endif
