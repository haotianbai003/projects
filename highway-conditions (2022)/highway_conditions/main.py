import datetime
import json
import requests
import time

EVENT_URL = "https://511on.ca/api/v2/get/event"
CONSTRUCTION_URL = "https://511on.ca/api/v2/get/constructionprojects"
ALERT_URL = "https://511on.ca/api/v2/get/alerts"
START_TIME = time.time()
END_TIME = START_TIME + 43200
WEST = {
        "Highway 401": {
            "direction": "Westbound",
            "startLat": 43.79333,
            "startLong": -79.21258,
            "endLat": 43.63521,
            "endLong": -79.67135,
        }
    }
EAST = {
        "Highway 401": {
            "direction": "Eastbound",
            "startLat": 43.63521,
            "startLong": -79.67135,
            "endLat": 43.79333,
            "endLong": -79.21258,
        }
    }


def pathfinding(start, end) -> dict[str, dict[str, str]]:
    # TODO - abandoned
    return []


def get_data(url) -> str:
    r = requests.get(EVENT_URL)
    if r.status_code != 200: raise Exception("Failed to connect to API.")
    output_json = json.dumps(r.json())
    return output_json


def ranges(n, start, end = 0):
    return start <= n <= end if end >= start else end <= n <= start


def in_range(lat, long, lat2, long2, path):
    if lat2 == 0 or long2 == 0:
        lat2, long2 = lat, long
    if (
        (ranges(lat, path.get("startLat"), path.get("endLat")) or 
        ranges(lat2, path.get("startLat"), path.get("endLat"))) and
        (ranges(long, path.get("startLong"), path.get("endLong")) or 
        ranges(long2, path.get("startLong"), path.get("endLong")))
    ):
        return True
    return False


def filter(path, lst) -> list[str]:
    items = []
    for item in json.loads(lst):
        hwy = item.get("RoadwayName")
        direction = item.get("DirectionOfTravel")
        start = item.get("StartDate")
        end = item.get("PlannedEndDate")
        lat = item.get("Latitude")
        long = item.get("Longitude")
        lat2 = item.get("LatitudeSecondary")
        long2 = item.get("LongitudeSecondary")
        if start is None:
            start = end
        if end is None:
            end = start

        if hwy not in path.keys():
            continue
        if direction != path[hwy]['direction']:
            continue
        if float(start) > END_TIME or float(end) < START_TIME:
            continue
        if not in_range(lat, long, lat2, long2, path.get(hwy)):
            continue
        else:
            items.append(item)
    return items


def get_alerts(path: list[str]):
    output = get_data(ALERT_URL)
    file = open(f"api_output/alerts_body_{time.time()}.json", "w")
    file.write(output)
    file.close()
    return filter(path, output)


def get_construction(path: list[str]):
    output = get_data(CONSTRUCTION_URL)
    file = open(f"api_output/constructions_body_{time.time()}.json", "w")
    file.write(output)
    file.close()
    return filter(path, output)


def get_events(path: list[str]):
    output = get_data(EVENT_URL)
    file = open(f"api_output/events_body_{time.time()}.json", "w")
    file.write(output)
    file.close()
    return filter(path, output)


def input() -> str:
    # TODO: abandoned
    return


def pretty_print_item(item):
    print(f"{item['RoadwayName']} {item['DirectionOfTravel']} from \
          {datetime.datetime.fromtimestamp(item['StartDate'])} to \
          {datetime.datetime.fromtimestamp(item['PlannedEndDate'])}")
    print(item["Description"])
    print(item["LanesAffected"])
    print()


def pretty_print(type, items):
    if len(items) == 0:
        return
    print("+++++++++++++++++++++++++++++++++++++++")
    print()
    print(f"The following {type} are in effect:")
    print()
    for item in items:
        pretty_print_item(item)
    print()
    print("+++++++++++++++++++++++++++++++++++++++")


def main():
    paths = [WEST, EAST]
    for path in paths:
        alerts = get_alerts(path)
        pretty_print("alerts", alerts)
        
        constructions = get_construction(path)
        pretty_print("constructions", constructions)
        
        events = get_events(path)
        pretty_print("events", events)

        print("=======================================")
        print("=======================================")
        print("=======================================")


if __name__ == "__main__":
    main()
