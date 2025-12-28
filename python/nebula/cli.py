import sys
import pathlib 

sys.path.insert(0, pathlib.Path(__file__).resolve().parents[2])

import argparse
import os 
import nebula

def main():
    parser = argparse.ArgumentParser(prog="Nebula")

    sub = parser.add_subparsers(dest="cmd", required=True)

    doctor = sub.add_parser("doctor")
    doctor.add_argument("--plugins", default=os.environ.get("NEBULA_PLUGINS", "plugins"))

    pl = sub.add_parser("plugins")
    plsub = pl.add_subparsers(dest="pcmd", required=True)

    ls = plsub.add_parser("list")
    ls.add_argument("dir", nargs="?", default="plugins")
   
    probe = plsub.add_parser("probe")
    probe.add_argument("dir", nargs="?", default="plugins")
    probe.add_argument("--on-load", action="store_true")

    args = parser.parse_args()

    if args.cmd == "doctor":
        print("Nebula version:", nebula.Core.create().version() if hasattr(nebula.Core, "create") else nebula.Core().version())
        print("Plugins dir:", args.plugins)
        for line in nebula.probe_plugins(args.plugins, False):
            print(" -", line)

    elif args.cmd == "plugins" and args.pcmd == "list":
        for f in nebula.list_plugin_files(args.dir):
            print(f)

    elif args.cmd == "plugins" and args.pcmd == "probe":
        for line in nebula.probe_plugins(args.dir, args.on_load):
            print(line)

if __name__ == "__main__":
    main()
