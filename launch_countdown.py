import time
from datetime import datetime, timedelta

def run_launch_countdown(current_height, target_height=347161):
    blocks_left = target_height - current_height
    seconds_left = blocks_left * 60 # 60 seconds per Chronopulse block
    
    target_date = datetime.now() + timedelta(seconds=seconds_left)
    
    print("=========================================================")
    print("         QMASK CORE TO QMC MAINNET MIGRATION WATCH")
    print("=========================================================")
    print(f" Current Block Height : #{current_height}")
    print(f" Target Freeze Height  : #{target_height}")
    print(f" Blocks Remaining      : {blocks_left} Blocks")
    print("---------------------------------------------------------")
    print(f" Estimated T-Zero Date : {target_date.strftime('%Y-%m-%d %H:%M:%S')} BST")
    print(f" Exact Countdown Time  : {blocks_left // 1440}d {(blocks_left % 1440) // 60}h {blocks_left % 60}m remaining")
    print("=========================================================")

if __name__ == "__main__":
    # Pulls your active telemetry block height directly
    run_launch_countdown(337823)
