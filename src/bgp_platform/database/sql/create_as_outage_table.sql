CREATE TABLE if not exists `{}` (
    asn text,
    outage_id int,
    s_time timestamp(0) without time zone not NULL,
    e_time timestamp(0) without time zone,
    duration interval DAY TO SECOND (0),
    max_outage_prefix_ratio decimal(4, 3) not NULL,
    max_outage_prefix_num int not NULL,
    total_prefix_num int not NULL,
    outage_level varchar(8) not NULL,
    outage_level_descr text not NULL,
    country text,
    as_name text,
    org_name text,
    as_type text,
    pre_vp_paths jsonb,
    eve_vp_paths jsonb,
    outage_prefixes jsonb,
    primary key(asn, outage_id)
);
