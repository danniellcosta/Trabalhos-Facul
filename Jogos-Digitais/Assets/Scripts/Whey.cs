using UnityEngine;

public class Whey : Halter
{
    public float duracao = 8.0f;

    protected override void Comer()
    {
        FindObjectOfType<GameManager>().WheyConsumido(this);
    }
}
