<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class="form-control" name="symbol">
                <option value=""></option>
                <?php foreach($stocks as $stock): ?>
                    <?=$value = $stock["stock"];?>
                    <option value="<?php echo $value ?>"><?=$value?></option>
                <?php endforeach ?>
            </select>
        </div>
        <div class="form-group">
            <input autofocus class="form-control" name="shares" placeholder="Shares" type="text"/>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="index.php">return</a> home
</div>
