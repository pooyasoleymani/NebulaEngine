from nebula import Core, ConfigError


core = Core.create()
print(core.version())

core.load_config("config.ini")