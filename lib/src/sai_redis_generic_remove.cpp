#include "sai_redis.h"
#include "meta/saiserialize.h"
#include "meta/saiattributelist.h"

sai_status_t internal_redis_generic_remove(
        _In_ sai_object_type_t object_type,
        _In_ const std::string &serialized_object_id)
{
    SWSS_LOG_ENTER();

    std::string str_object_type = sai_serialize_object_type(object_type);

    std::string key = str_object_type + ":" + serialized_object_id;

    SWSS_LOG_DEBUG("generic remove key: %s", key.c_str());

    if (g_record)
    {
        recordLine("r|" + key);
    }

    g_asicState->del(key, "remove");

    return SAI_STATUS_SUCCESS;
}

sai_status_t redis_generic_remove(
        _In_ sai_object_type_t object_type,
        _In_ sai_object_id_t object_id)
{
    SWSS_LOG_ENTER();

    if (object_id == SAI_NULL_OBJECT_ID)
    {
        SWSS_LOG_ERROR("object id is zero on object type %d", object_type);

        return SAI_STATUS_INVALID_PARAMETER;
    }

    std::string str_object_id = sai_serialize_object_id(object_id);

    return internal_redis_generic_remove(
            object_type,
            str_object_id);
}

sai_status_t redis_generic_remove_fdb_entry(
        _In_ const sai_fdb_entry_t* fdb_entry)
{
    SWSS_LOG_ENTER();

    std::string str_fdb_entry = sai_serialize_fdb_entry(*fdb_entry);

    return internal_redis_generic_remove(
            SAI_OBJECT_TYPE_FDB,
            str_fdb_entry);
}

sai_status_t redis_generic_remove_neighbor_entry(
        _In_ const sai_neighbor_entry_t* neighbor_entry)
{
    SWSS_LOG_ENTER();

    std::string str_neighbor_entry = sai_serialize_neighbor_entry(*neighbor_entry);

    return internal_redis_generic_remove(
            SAI_OBJECT_TYPE_NEIGHBOR,
            str_neighbor_entry);
}

sai_status_t redis_generic_remove_route_entry(
        _In_ const sai_unicast_route_entry_t* unicast_route_entry)
{
    SWSS_LOG_ENTER();

    std::string str_route_entry = sai_serialize_route_entry(*unicast_route_entry);

    return internal_redis_generic_remove(
            SAI_OBJECT_TYPE_ROUTE,
            str_route_entry);
}

sai_status_t redis_generic_remove_vlan(
        _In_ sai_vlan_id_t vlan_id)
{
    SWSS_LOG_ENTER();

    std::string str_vlan_id = sai_serialize_vlan_id(vlan_id);

    return internal_redis_generic_remove(
            SAI_OBJECT_TYPE_VLAN,
            str_vlan_id);
}
