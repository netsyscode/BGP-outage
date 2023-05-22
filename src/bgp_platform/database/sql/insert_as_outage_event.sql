INSERT INTO {table_name} (
        country,
        as_name,
        org_name,
        as_type,
        s_time,
        e_time,
        duration,
        total_prefix_num,
        max_outage_prefix_num,
        max_outage_prefix_ratio,
        pre_vp_paths,
        eve_vp_paths,
        outage_prefixes,
        outage_level,
        outage_level_descr,
        asn,
        outage_id
    )
VALUES (
        '{country}',
        '{as_name}',
        '{org_name}',
        '{as_type}',
        '{s_time}',
        NULL,
        NULL,
        '{total_prefix_num}',
        '{max_outage_prefix_num}',
        '{max_outage_prefix_ratio}',
        '{pre_vp_paths}',
        '{eve_vp_paths}',
        '{outage_prefixes}',
        '{outage_level}',
        '{outage_level_descr}',
        '{asn}',
        '{outage_id}'
    );